/*
 * 贪吃蛇 Win32 GUI 版
 * 编译: gcc -o snake_win.exe snake_win.c -lgdi32 -mwindows
 *
 * 控制:
 *   W/A/S/D 或 方向键  — 移动
 *   P                  — 暂停/继续
 *   R                  — 重新开始
 *   ESC                — 退出
 */

#define UNICODE
#define _UNICODE
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* ─── 游戏参数 ────────────────────────────────────────────── */
#define GRID_W      25           /* 格列数（固定）      */
#define GRID_H      20           /* 格行数（固定）      */
#define MAX_LEN     (GRID_W * GRID_H)
#define TIMER_ID    1
#define SPEED_BASE  160          /* 初始帧间隔 ms       */
#define SPEED_MIN    55          /* 最快帧间隔 ms       */
/* 以下布局参数运行时根据屏幕分辨率自适应计算 */
static int CELL, GW, GH, PANEL_W, WIN_CW, WIN_CH;

/* ─── 方向 ────────────────────────────────────────────────── */
#define DIR_UP    0
#define DIR_DOWN  1
#define DIR_LEFT  2
#define DIR_RIGHT 3

typedef struct { int x, y; } Point;

/* ─── 颜色宏 ──────────────────────────────────────────────── */
#define C_BG        RGB(28,  28,  36)
#define C_GRID      RGB(42,  42,  55)
#define C_BORDER    RGB(60,  60,  80)
#define C_HEAD      RGB(50,  230, 110)
#define C_BODY      RGB(30,  160,  70)
#define C_FOOD      RGB(255,  80,  80)
#define C_PANEL     RGB(18,  18,  24)
#define C_TITLE     RGB(50,  230, 110)
#define C_SCORE     RGB(255, 220,  60)
#define C_BEST      RGB(255, 160,  60)
#define C_TEXT      RGB(200, 200, 200)
#define C_DIM       RGB(110, 110, 130)
#define C_PAUSE     RGB(50,  230, 110)
#define C_GO_BORDER RGB(220,  60,  60)
#define C_GO_TITLE  RGB(220,  60,  60)

/* ─── 全局状态 ───────────────────────────────────────────── */
static Point snake[MAX_LEN];
static int   sLen, dir, nextDir;
static Point food;
static int   score, highScore;
static int   gameOver, paused;
static int   speed, autoPlay;

static HWND  hWnd;
static HFONT hFontBig, hFontMed, hFontSmall;

/* ════════════════════════════════════════════════════════════
   工具函数
   ════════════════════════════════════════════════════════════ */
static int imax(int a, int b) { return a > b ? a : b; }

static HBRUSH mkBrush(COLORREF c) { return CreateSolidBrush(c); }
static HPEN   mkPen(COLORREF c, int w) { return CreatePen(PS_SOLID, w, c); }

/* 在 memDC 上画一个圆角矩形格子 */
static void DrawCell(HDC dc, int gx, int gy, COLORREF fill, COLORREF border) {
    int pad = CELL * 2 / 26; if (pad < 1) pad = 1;
    int x1 = gx * CELL + pad,        y1 = gy * CELL + pad;
    int x2 = gx * CELL + CELL - pad, y2 = gy * CELL + CELL - pad;
    int rnd = CELL * 7 / 26;
    HBRUSH br  = mkBrush(fill);
    HPEN   pen = mkPen(border, 1);
    HBRUSH ob  = SelectObject(dc, br);
    HPEN   op  = SelectObject(dc, pen);
    RoundRect(dc, x1, y1, x2, y2, rnd, rnd);
    SelectObject(dc, ob); SelectObject(dc, op);
    DeleteObject(br); DeleteObject(pen);
}

/* 居中文字（单行） */
static void TextCenterX(HDC dc, int left, int right, int y, const wchar_t *s) {
    int h = WIN_CH * 40 / 520; if (h < 18) h = 18;
    RECT r = {left, y, right, y + h};
    DrawTextW(dc, s, -1, &r, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
}

/* ════════════════════════════════════════════════════════════
   自动游戏 (Hamilton 回路 + BFS 捷径)   按 F 键切换
   ════════════════════════════════════════════════════════════
   回路构造（要求 GRID_H 为偶数，本游戏 GRID_H=20 满足）：
     • 列 1..GRID_W-1 按行蛇形扫描：偶数行向右，奇数行向左
     • 列 0 作为竖向返回通道：从 (0,GRID_H-1) 向上到 (0,1)
     • 首尾相连：…→(0,1)→(0,0)→(1,0)→…
   索引示例 (GRID_W=25, GRID_H=20, 共 500 格)：
     (0,0)=0, (1,0)=1, …, (24,0)=24,
     (24,1)=25, (23,1)=26, …, (1,1)=48,
     (1,2)=49, …, (1,19)=480,
     (0,19)=481, (0,18)=482, …, (0,1)=499
   ════════════════════════════════════════════════════════════ */
static const int AUTO_DX[4] = { 0,  0, -1,  1}; /* UP DOWN LEFT RIGHT */
static const int AUTO_DY[4] = {-1,  1,  0,  0};
static const int AUTO_DD[4] = {DIR_UP, DIR_DOWN, DIR_LEFT, DIR_RIGHT};

static int     autoBfsVis[GRID_H][GRID_W];
static int     autoBfsPX[GRID_H][GRID_W];
static int     autoBfsPY[GRID_H][GRID_W];
typedef struct { short x, y; } BfsCell;
static BfsCell autoBfsQ[MAX_LEN];

/* 判断 (x,y) 是否是蛇身（只检查前 len 节） */
static int SnakeAt(int x, int y, int len) {
    for (int i = 0; i < len; i++)
        if (snake[i].x == x && snake[i].y == y) return 1;
    return 0;
}

/*
 * BFS 从 (sx,sy) 到 (tx,ty)，蛇前 blockLen 节为障碍。
 * 返回第一步方向；无路径则返回 -1。
 */
static int BfsDir(int sx, int sy, int tx, int ty, int blockLen) {
    if (sx == tx && sy == ty) return -1;
    memset(autoBfsVis, 0, sizeof(autoBfsVis));
    autoBfsVis[sy][sx] = 1;
    autoBfsPX[sy][sx] = -1;
    autoBfsPY[sy][sx] = -1;
    int qh = 0, qt = 0;
    autoBfsQ[qt++] = (BfsCell){(short)sx, (short)sy};

    while (qh < qt) {
        BfsCell cur = autoBfsQ[qh++];
        if (cur.x == tx && cur.y == ty) break;
        for (int d = 0; d < 4; d++) {
            int nx = cur.x + AUTO_DX[d], ny = cur.y + AUTO_DY[d];
            if ((unsigned)nx >= (unsigned)GRID_W ||
                (unsigned)ny >= (unsigned)GRID_H) continue;
            if (autoBfsVis[ny][nx]) continue;
            if (SnakeAt(nx, ny, blockLen)) continue;
            autoBfsVis[ny][nx] = 1;
            autoBfsPX[ny][nx] = cur.x;
            autoBfsPY[ny][nx] = cur.y;
            autoBfsQ[qt++] = (BfsCell){(short)nx, (short)ny};
        }
    }
    if (!autoBfsVis[ty][tx]) return -1;

    /* 回溯：找从起点出发的第一格 */
    int cx = tx, cy = ty;
    while (autoBfsPX[cy][cx] != sx || autoBfsPY[cy][cx] != sy) {
        int px = autoBfsPX[cy][cx], py = autoBfsPY[cy][cx];
        cx = px; cy = py;
    }
    for (int d = 0; d < 4; d++)
        if (cx == sx + AUTO_DX[d] && cy == sy + AUTO_DY[d]) return AUTO_DD[d];
    return -1;
}

/*
 * 返回格子 (x,y) 在 Hamilton 回路中的索引 (O(1))
 */
static int HamIndex(int x, int y) {
    if (x == 0) {
        if (y == 0) return 0;
        /* 列 0 竖向返回通道 */
        return (GRID_W - 1) * GRID_H + (GRID_H - y);
    }
    /* 蛇形扫描区 (cols 1..GRID_W-1) */
    int base = 1 + y * (GRID_W - 1);
    if (y % 2 == 0) return base + (x - 1);
    else             return base + (GRID_W - 1 - x);
}

/*
 * 给定当前 Hamilton 索引 hIdx，返回沿回路走下一步的方向。
 */
static int HamNextDir(int hIdx) {
    int N    = GRID_W * GRID_H;
    int next = (hIdx + 1) % N;
    /* 反解 next 对应格子 (nx, ny) */
    int nx, ny;
    if (next == 0) {
        nx = 0; ny = 0;
    } else if (next > (GRID_W - 1) * GRID_H) {
        /* 列 0 通道：(GRID_W-1)*GRID_H + (GRID_H - y) = next */
        ny = (GRID_W - 1) * GRID_H + GRID_H - next;
        nx = 0;
    } else {
        /* 蛇形扫描区：next = 1 + ny*(GRID_W-1) + col_off */
        int idx0    = next - 1;
        ny          = idx0 / (GRID_W - 1);
        int col_off = idx0 % (GRID_W - 1);
        if (ny % 2 == 0) nx = 1 + col_off;
        else              nx = GRID_W - 1 - col_off;
    }
    int dx = nx - snake[0].x, dy = ny - snake[0].y;
    if (dx ==  1) return DIR_RIGHT;
    if (dx == -1) return DIR_LEFT;
    if (dy ==  1) return DIR_DOWN;
    return DIR_UP;
}

/*
 * AI 决策：Hamilton 回路 + BFS 捷径
 *
 * 核心问题：走过捷径后，蛇身不再占据回路上的「连续」格，
 * 此时 HamNextDir 指向的下一格可能已被蛇身占据，直接跟随
 * 回路会撞身死亡。
 *
 * 三级决策：
 *   1. 捷径：食物在回路顺序上位于 [head, tail) → BFS 直奔食物
 *   2. 回路：下一回路格安全 → 沿 Hamilton 回路走一步
 *   3. 对齐：回路格被占（快捷产生的非连续蛇身） → BFS 追尾，
 *      让蛇重新与回路对齐，最终彻底恢复连续性
 */
static int AutoDecide(void) {
    int N    = GRID_W * GRID_H;
    int hIdx = HamIndex(snake[0].x, snake[0].y);
    int tIdx = HamIndex(snake[sLen - 1].x, snake[sLen - 1].y);
    int fIdx = HamIndex(food.x, food.y);

    /* 头到食物 / 头到尾 的 Hamilton 顺序正向距离 */
    int distToFood = (fIdx - hIdx + N) % N;
    int distToTail = (tIdx - hIdx + N) % N;

    /* ── 级别 1：捷径 ── */
    if (distToFood > 0 && distToFood < distToTail) {
        int fd = BfsDir(snake[0].x, snake[0].y,
                        food.x, food.y, sLen);
        if (fd != -1) return fd;
    }

    /* ── 级别 2：沿 Hamilton 回路走，若安全直接返回 ── */
    int hamDir = HamNextDir(hIdx);
    {
        int nhx = snake[0].x + AUTO_DX[hamDir];
        int nhy = snake[0].y + AUTO_DY[hamDir];
        /* sLen-1：尾节下一帧会移走，不算障碍 */
        if (!SnakeAt(nhx, nhy, sLen - 1))
            return hamDir;
    }

    /* ── 级别 3：回路下一格被占（捷径导致非连续蛇身），
     *            BFS 追尾让蛇重新与回路对齐 ── */
    int tailD = BfsDir(snake[0].x, snake[0].y,
                       snake[sLen - 1].x, snake[sLen - 1].y,
                       sLen - 1);
    if (tailD != -1) return tailD;

    /* 最终兜底：选任意不撞身的方向 */
    for (int d = 0; d < 4; d++) {
        int nx = snake[0].x + AUTO_DX[d], ny = snake[0].y + AUTO_DY[d];
        if ((unsigned)nx >= (unsigned)GRID_W ||
            (unsigned)ny >= (unsigned)GRID_H) continue;
        if (!SnakeAt(nx, ny, sLen - 1)) return AUTO_DD[d];
    }
    return hamDir; /* 无路可走（极端情况） */
}

/* ════════════════════════════════════════════════════════════
   游戏逻辑
   ════════════════════════════════════════════════════════════ */
static void SpawnFood(void) {
    int ok;
    do {
        ok = 1;
        food.x = rand() % GRID_W;
        food.y = rand() % GRID_H;
        for (int i = 0; i < sLen; i++)
            if (snake[i].x == food.x && snake[i].y == food.y) { ok = 0; break; }
    } while (!ok);
}

static void InitGame(void) {
    sLen    = 4;
    dir     = DIR_RIGHT;
    nextDir = DIR_RIGHT;
    score   = 0;
    gameOver = 0;
    paused   = 0;
    speed    = SPEED_BASE;
    for (int i = 0; i < sLen; i++) {
        snake[i].x = GRID_W / 2 - i;
        snake[i].y = GRID_H / 2;
    }
    SpawnFood();
}

static void Update(void) {
    if (gameOver || paused) return;
    if (autoPlay) { int d = AutoDecide(); if (d != -1) nextDir = d; }

    dir = nextDir;
    Point tail = snake[sLen - 1];
    for (int i = sLen - 1; i > 0; i--) snake[i] = snake[i - 1];

    switch (dir) {
        case DIR_UP:    snake[0].y--; break;
        case DIR_DOWN:  snake[0].y++; break;
        case DIR_LEFT:  snake[0].x--; break;
        case DIR_RIGHT: snake[0].x++; break;
    }
    (void)tail;

    /* 碰墙 */
    if (snake[0].x < 0 || snake[0].x >= GRID_W ||
        snake[0].y < 0 || snake[0].y >= GRID_H) {
        gameOver = 1; return;
    }
    /* 碰身 */
    for (int i = 1; i < sLen; i++)
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
            gameOver = 1; return;
        }
    /* 吃食物 */
    if (snake[0].x == food.x && snake[0].y == food.y) {
        sLen++;
        score += 10;
        if (score > highScore) highScore = score;
        speed = imax(SPEED_MIN, SPEED_BASE - (score / 50) * 18);
        KillTimer(hWnd, TIMER_ID);
        SetTimer(hWnd, TIMER_ID, speed, NULL);
        SpawnFood();
    }
}

/* ════════════════════════════════════════════════════════════
   绘制
   ════════════════════════════════════════════════════════════ */
static void DrawOverlayBox(HDC dc, int x1, int y1, int x2, int y2, COLORREF border) {
    HBRUSH br = mkBrush(RGB(15, 15, 22));
    FillRect(dc, &(RECT){x1, y1, x2, y2}, br);
    DeleteObject(br);
    HPEN pen = mkPen(border, 2);
    HPEN op  = SelectObject(dc, pen);
    HBRUSH ob = SelectObject(dc, GetStockObject(NULL_BRUSH));
    Rectangle(dc, x1, y1, x2, y2);
    SelectObject(dc, op); SelectObject(dc, ob);
    DeleteObject(pen);
}

static void DrawGame(HDC dc) {
    /* ── 游戏区背景 ── */
    HBRUSH bgBr = mkBrush(C_BG);
    RECT bgR = {0, 0, GW, GH};
    FillRect(dc, &bgR, bgBr);
    DeleteObject(bgBr);

    /* ── 网格点 ── */
    HBRUSH dotBr = mkBrush(C_GRID);
    for (int x = 0; x < GRID_W; x++)
        for (int y = 0; y < GRID_H; y++) {
            int cx = x * CELL + CELL / 2, cy = y * CELL + CELL / 2;
            int dotR = CELL / 26; if (dotR < 1) dotR = 1;
            RECT dr = {cx-dotR, cy-dotR, cx+dotR, cy+dotR};
            FillRect(dc, &dr, dotBr);
        }
    DeleteObject(dotBr);

    /* ── 边框 ── */
    HPEN borderPen = mkPen(C_BORDER, 2);
    HPEN op = SelectObject(dc, borderPen);
    HBRUSH ob = SelectObject(dc, GetStockObject(NULL_BRUSH));
    Rectangle(dc, 0, 0, GW, GH);
    SelectObject(dc, op); SelectObject(dc, ob);
    DeleteObject(borderPen);

    /* ── 食物 ── */
    {
        int fo = CELL * 3 / 26; if (fo < 2) fo = 2;
        int fx = food.x * CELL + fo, fy = food.y * CELL + fo;
        int fr = CELL - 2 * fo;
        HBRUSH fb = mkBrush(C_FOOD);
        HPEN fp = mkPen(RGB(255, 120, 120), 1);
        HBRUSH ob2 = SelectObject(dc, fb);
        HPEN op2   = SelectObject(dc, fp);
        Ellipse(dc, fx, fy, fx + fr, fy + fr);
        /* 小高光 */
        HBRUSH wb = mkBrush(RGB(255,200,200));
        SelectObject(dc, wb);
        SelectObject(dc, GetStockObject(NULL_PEN));
        Ellipse(dc, fx+CELL*3/26, fy+CELL*2/26, fx+CELL*8/26, fy+CELL*6/26);
        SelectObject(dc, ob2); SelectObject(dc, op2);
        DeleteObject(fb); DeleteObject(fp); DeleteObject(wb);
    }

    /* ── 蛇身 ── */
    for (int i = sLen - 1; i >= 1; i--)
        DrawCell(dc, snake[i].x, snake[i].y, C_BODY, RGB(20,110,50));

    /* ── 蛇头 ── */
    DrawCell(dc, snake[0].x, snake[0].y, C_HEAD, RGB(40,200,90));

    /* ── 右侧面板 ── */
    int px = GW;
    HBRUSH panelBr = mkBrush(C_PANEL);
    RECT panelR = {px, 0, WIN_CW, WIN_CH};
    FillRect(dc, &panelR, panelBr);
    DeleteObject(panelBr);

    /* 分隔线 */
    HPEN divPen = mkPen(RGB(60,60,80), 1);
    HPEN divOld = SelectObject(dc, divPen);
    MoveToEx(dc, px, 0, NULL); LineTo(dc, px, WIN_CH);
    SelectObject(dc, divOld); DeleteObject(divPen);

    /* 面板文字（Y 坐标按 WIN_CH/520 比例缩放） */
    SetBkMode(dc, TRANSPARENT);
    wchar_t buf[64];
#define PY(y) (WIN_CH*(y)/520)

    /* 标题 */
    SelectObject(dc, hFontBig);
    SetTextColor(dc, C_TITLE);
    TextCenterX(dc, px, WIN_CW, PY(18), L"SNAKE");

    /* 装饰线 */
    {
        int accM = CELL * 20 / 26;
        HPEN accentPen = mkPen(C_TITLE, 1);
        HPEN accentOld = SelectObject(dc, accentPen);
        MoveToEx(dc, px+accM, PY(60), NULL); LineTo(dc, WIN_CW-accM, PY(60));
        SelectObject(dc, accentOld); DeleteObject(accentPen);
    }

    /* SCORE */
    SelectObject(dc, hFontSmall);
    SetTextColor(dc, C_DIM);
    TextCenterX(dc, px, WIN_CW, PY(72), L"SCORE");
    SelectObject(dc, hFontBig);
    SetTextColor(dc, C_SCORE);
    _swprintf(buf, L"%d", score);
    TextCenterX(dc, px, WIN_CW, PY(95), buf);

    /* BEST */
    SelectObject(dc, hFontSmall);
    SetTextColor(dc, C_DIM);
    TextCenterX(dc, px, WIN_CW, PY(145), L"BEST");
    SelectObject(dc, hFontMed);
    SetTextColor(dc, C_BEST);
    _swprintf(buf, L"%d", highScore);
    TextCenterX(dc, px, WIN_CW, PY(168), buf);

    /* Level & Length */
    SelectObject(dc, hFontSmall);
    SetTextColor(dc, C_TEXT);
    _swprintf(buf, L"Level : %d", score / 50 + 1);
    TextCenterX(dc, px, WIN_CW, PY(220), buf);
    _swprintf(buf, L"Length: %d", sLen);
    TextCenterX(dc, px, WIN_CW, PY(245), buf);

    /* 自动模式指示 */
    SelectObject(dc, hFontSmall);
    if (autoPlay) {
        SetTextColor(dc, RGB(80, 255, 140));
        TextCenterX(dc, px, WIN_CW, PY(268), L"[ AUTO  ON  ]");
    } else {
        SetTextColor(dc, C_DIM);
        TextCenterX(dc, px, WIN_CW, PY(268), L"[ AUTO  OFF ]");
    }

    /* 操作说明 */
    SetTextColor(dc, C_DIM);
    TextCenterX(dc, px, WIN_CW, PY(295), L"— Controls —");
    TextCenterX(dc, px, WIN_CW, PY(323), L"WASD / Arrows");
    TextCenterX(dc, px, WIN_CW, PY(345), L"P  Pause");
    TextCenterX(dc, px, WIN_CW, PY(367), L"R  Restart");
    TextCenterX(dc, px, WIN_CW, PY(389), L"ESC  Quit");
    TextCenterX(dc, px, WIN_CW, PY(411), L"F    Auto");
#undef PY

    /* ── 暂停遮罩 ── */
    if (paused && !gameOver) {
        int bw = CELL*120/26, bh = CELL*50/26;
        int bx1 = GW/2-bw, by1 = GH/2-bh, bx2 = GW/2+bw, by2 = GH/2+bh;
        DrawOverlayBox(dc, bx1, by1, bx2, by2, C_PAUSE);
        SelectObject(dc, hFontBig);
        SetTextColor(dc, C_PAUSE);
        RECT pr = {bx1, by1+CELL*5/26, bx2, by1+CELL*50/26};
        DrawTextW(dc, L"PAUSED", -1, &pr, DT_CENTER|DT_SINGLELINE|DT_VCENTER);
        SelectObject(dc, hFontSmall);
        SetTextColor(dc, C_DIM);
        RECT pr2 = {bx1, by1+CELL*55/26, bx2, by2-CELL*5/26};
        DrawTextW(dc, L"Press P to continue", -1, &pr2, DT_CENTER|DT_SINGLELINE|DT_VCENTER);
    }

    /* ── 游戏结束遮罩 ── */
    if (gameOver) {
        int bw = CELL*145/26, bh = CELL*90/26;
        int bx1 = GW/2-bw, by1 = GH/2-bh, bx2 = GW/2+bw, by2 = GH/2+bh;
        DrawOverlayBox(dc, bx1, by1, bx2, by2, C_GO_BORDER);
        SelectObject(dc, hFontBig);
        SetTextColor(dc, C_GO_TITLE);
        RECT r1 = {bx1, by1+CELL*8/26, bx2, by1+CELL*56/26};
        DrawTextW(dc, L"GAME OVER", -1, &r1, DT_CENTER|DT_SINGLELINE|DT_VCENTER);

        SelectObject(dc, hFontMed);
        SetTextColor(dc, C_TEXT);
        _swprintf(buf, L"Score : %d", score);
        RECT r2 = {bx1, by1+CELL*60/26, bx2, by1+CELL*90/26};
        DrawTextW(dc, buf, -1, &r2, DT_CENTER|DT_SINGLELINE|DT_VCENTER);
        _swprintf(buf, L"Best  : %d", highScore);
        RECT r3 = {bx1, by1+CELL*90/26, bx2, by1+CELL*118/26};
        DrawTextW(dc, buf, -1, &r3, DT_CENTER|DT_SINGLELINE|DT_VCENTER);

        SelectObject(dc, hFontSmall);
        SetTextColor(dc, C_TITLE);
        RECT r4 = {bx1, by1+CELL*125/26, bx2, by2-CELL*5/26};
        DrawTextW(dc, L"R - Restart        ESC - Quit", -1, &r4,
                  DT_CENTER|DT_SINGLELINE|DT_VCENTER);
    }
}

/* ════════════════════════════════════════════════════════════
   布局与字体重改（拖动窗口时调用）
   ════════════════════════════════════════════════════════════ */
static void RecreateLayout(int cw, int ch) {
    int cellH = ch / GRID_H;
    int cellW = cw * 26 / (GRID_W * 26 + 170);
    CELL = (cellH < cellW) ? cellH : cellW;
    if (CELL < 16) CELL = 16;
    if (CELL > 64) CELL = 64;
    GW      = GRID_W * CELL;
    GH      = GRID_H * CELL;
    PANEL_W = CELL * 170 / 26;
    WIN_CW  = GW + PANEL_W;
    WIN_CH  = GH;
    if (hFontBig)   { DeleteObject(hFontBig);   hFontBig   = NULL; }
    if (hFontMed)   { DeleteObject(hFontMed);   hFontMed   = NULL; }
    if (hFontSmall) { DeleteObject(hFontSmall); hFontSmall = NULL; }
    hFontBig   = CreateFontW(CELL*34/26, 0,0,0, FW_BOLD,     FALSE,FALSE,FALSE,
                             DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                             CLEARTYPE_QUALITY, DEFAULT_PITCH, L"Segoe UI");
    hFontMed   = CreateFontW(CELL*24/26, 0,0,0, FW_SEMIBOLD, FALSE,FALSE,FALSE,
                             DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                             CLEARTYPE_QUALITY, DEFAULT_PITCH, L"Segoe UI");
    hFontSmall = CreateFontW(CELL*17/26, 0,0,0, FW_NORMAL,   FALSE,FALSE,FALSE,
                             DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                             CLEARTYPE_QUALITY, DEFAULT_PITCH, L"Segoe UI");
}

/* ════════════════════════════════════════════════════════════
   窗口过程
   ════════════════════════════════════════════════════════════ */
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {

    case WM_KEYDOWN:
        switch (wParam) {
        case VK_UP:    case 'W': autoPlay = 0; if (dir != DIR_DOWN)  nextDir = DIR_UP;    break;
        case VK_DOWN:  case 'S': autoPlay = 0; if (dir != DIR_UP)    nextDir = DIR_DOWN;  break;
        case VK_LEFT:  case 'A': autoPlay = 0; if (dir != DIR_RIGHT) nextDir = DIR_LEFT;  break;
        case VK_RIGHT: case 'D': autoPlay = 0; if (dir != DIR_LEFT)  nextDir = DIR_RIGHT; break;
        case 'F':
            if (!gameOver) {
                autoPlay = !autoPlay;
                if (autoPlay && paused) paused = 0;
                InvalidateRect(hwnd, NULL, FALSE);
            }
            break;
        case 'P':
            if (!gameOver) { paused = !paused; InvalidateRect(hwnd, NULL, FALSE); }
            break;
        case 'R':
            KillTimer(hwnd, TIMER_ID);
            InitGame();
            SetTimer(hwnd, TIMER_ID, speed, NULL);
            InvalidateRect(hwnd, NULL, FALSE);
            break;
        case VK_ESCAPE:
            PostQuitMessage(0);
            break;
        }
        return 0;

    case WM_TIMER:
        if (wParam == TIMER_ID) {
            Update();
            InvalidateRect(hwnd, NULL, FALSE);
        }
        return 0;

    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        /* 双缓冲，防闪烁 */
        RECT cr; GetClientRect(hwnd, &cr);
        HDC   memDC  = CreateCompatibleDC(hdc);
        HBITMAP bmp  = CreateCompatibleBitmap(hdc, cr.right, cr.bottom);
        HBITMAP obmp = SelectObject(memDC, bmp);

        DrawGame(memDC);

        BitBlt(hdc, 0, 0, cr.right, cr.bottom, memDC, 0, 0, SRCCOPY);

        SelectObject(memDC, obmp);
        DeleteObject(bmp);
        DeleteDC(memDC);

        EndPaint(hwnd, &ps);
        return 0;
    }

    case WM_SIZE:
        if (wParam != SIZE_MINIMIZED) {
            int cw = LOWORD(lParam), ch = HIWORD(lParam);
            if (cw > 0 && ch > 0) {
                RecreateLayout(cw, ch);
                InvalidateRect(hwnd, NULL, FALSE);
            }
        }
        return 0;

    case WM_GETMINMAXINFO: {
        /* 最小窗口：保证 CELL >= 16 */
        MINMAXINFO *mmi = (MINMAXINFO *)lParam;
        RECT rc = {0, 0, GRID_W*16 + 16*170/26, GRID_H*16};
        AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
        mmi->ptMinTrackSize.x = rc.right  - rc.left;
        mmi->ptMinTrackSize.y = rc.bottom - rc.top;
        return 0;
    }

    case WM_DESTROY:
        KillTimer(hwnd, TIMER_ID);
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

/* ════════════════════════════════════════════════════════════
   WinMain
   ════════════════════════════════════════════════════════════ */
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev,
                   LPSTR lpCmd, int nShow) {
    (void)hPrev; (void)lpCmd;
    srand((unsigned)time(NULL));

    /* 初始布局：根据屏幕分辨率计算 */
    {
        int scrW = GetSystemMetrics(SM_CXSCREEN);
        int scrH = GetSystemMetrics(SM_CYSCREEN);
        RecreateLayout(scrW * 75 / 100, scrH * 85 / 100);
    }

    /* 注册窗口类 */
    WNDCLASSEXW wc = {0};
    wc.cbSize        = sizeof(wc);
    wc.style         = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc   = WndProc;
    wc.hInstance     = hInst;
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = NULL;
    wc.lpszClassName = L"SnakeWin";
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    RegisterClassExW(&wc);

    /* 计算窗口大小（含边框标题） */
    DWORD style = WS_OVERLAPPEDWINDOW;
    RECT rc = {0, 0, WIN_CW, WIN_CH};
    AdjustWindowRect(&rc, style, FALSE);
    int ww = rc.right  - rc.left;
    int wh = rc.bottom - rc.top;
    int cx = (GetSystemMetrics(SM_CXSCREEN) - ww) / 2;
    int cy = (GetSystemMetrics(SM_CYSCREEN) - wh) / 2;

    hWnd = CreateWindowExW(0, L"SnakeWin", L"贪吃蛇  Snake",
                           style, cx, cy, ww, wh,
                           NULL, NULL, hInst, NULL);

    InitGame();
    SetTimer(hWnd, TIMER_ID, speed, NULL);
    ShowWindow(hWnd, nShow);
    UpdateWindow(hWnd);

    MSG msg;
    while (GetMessageW(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    DeleteObject(hFontBig);
    DeleteObject(hFontMed);
    DeleteObject(hFontSmall);
    
    return (int)msg.wParam;
}
