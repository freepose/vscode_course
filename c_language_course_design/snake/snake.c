/*
 * 贪吃蛇游戏 (Snake Game)
 * 编译: gcc -o snake.exe snake.c
 * 运行: snake.exe
 *
 * 控制方式:
 *   W / 上方向键  —— 向上
 *   S / 下方向键  —— 向下
 *   A / 左方向键  —— 向左
 *   D / 右方向键  —— 向右
 *   P             —— 暂停/继续
 *   ESC           —— 退出
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

/* ── 游戏区域尺寸 ─────────────────────────────────────────── */
#define W  40      /* 游戏区宽度 (格数) */
#define H  20      /* 游戏区高度 (格数) */
#define MAX_LEN (W * H)

/* ── 方向常量 ────────────────────────────────────────────── */
#define UP    0
#define DOWN  1
#define LEFT  2
#define RIGHT 3

typedef struct { int x, y; } Point;

/* ── 全局状态 ────────────────────────────────────────────── */
static HANDLE  hCon;
static Point   snake[MAX_LEN];
static int     sLen;       /* 蛇身长度   */
static int     dir;        /* 当前方向   */
static int     score;
static int     gameOver;   /* 0=进行中 1=死亡 2=ESC退出 */
static int     speed;      /* Sleep 毫秒 */
static Point   food;
static int     highScore = 0;

/* ════════════════════════════════════════════════════════
   控制台辅助函数
   ════════════════════════════════════════════════════════ */
static void hideCursor(void) {
    CONSOLE_CURSOR_INFO ci = {1, FALSE};
    SetConsoleCursorInfo(hCon, &ci);
}
static void showCursor(void) {
    CONSOLE_CURSOR_INFO ci = {1, TRUE};
    SetConsoleCursorInfo(hCon, &ci);
}
static void gotoXY(int x, int y) {
    COORD c = {(SHORT)x, (SHORT)y};
    SetConsoleCursorPosition(hCon, c);
}
static void setColor(int c) {
    SetConsoleTextAttribute(hCon, c);
}
/* 在指定位置打印一个字符，然后恢复默认颜色 */
static void putAt(int x, int y, int col, char ch) {
    gotoXY(x, y);
    setColor(col);
    putchar(ch);
    setColor(7);
}
/* 清除指定位置 */
static void clearAt(int x, int y) {
    gotoXY(x, y); putchar(' ');
}

/* ════════════════════════════════════════════════════════
   绘制函数
   ════════════════════════════════════════════════════════ */

/* 绘制边框 (游戏区: x=[1..W], y=[1..H]) */
static void drawBorder(void) {
    setColor(14); /* 黄色 */

    /* 顶部 */
    gotoXY(0, 0);
    putchar('+');
    for (int x = 0; x < W; x++) putchar('-');
    putchar('+');

    /* 底部 */
    gotoXY(0, H + 1);
    putchar('+');
    for (int x = 0; x < W; x++) putchar('-');
    putchar('+');

    /* 左右 */
    for (int y = 1; y <= H; y++) {
        gotoXY(0,     y); putchar('|');
        gotoXY(W + 1, y); putchar('|');
    }
    setColor(7);
}

/* 侧边栏 */
static void drawSidebar(void) {
    int sx = W + 4;

    setColor(11); /* 青色标题 */
    gotoXY(sx, 1);  printf("  SNAKE GAME ");

    setColor(14); /* 黄色数据 */
    gotoXY(sx, 3);  printf("Score : %5d", score);
    gotoXY(sx, 4);  printf("Best  : %5d", highScore);
    gotoXY(sx, 5);  printf("Level : %5d", score / 50 + 1);

    setColor(7);  /* 默认色说明 */
    gotoXY(sx, 7);  printf("Controls:");
    gotoXY(sx, 8);  printf("  W/Up    Up");
    gotoXY(sx, 9);  printf("  S/Down  Down");
    gotoXY(sx, 10); printf("  A/Left  Left");
    gotoXY(sx, 11); printf("  D/Right Right");
    gotoXY(sx, 12); printf("  P       Pause");
    gotoXY(sx, 13); printf("  ESC     Quit");

    setColor(10);
    gotoXY(sx, 15); printf("  @  = Head");
    setColor(2);
    gotoXY(sx, 16); printf("  o  = Body");
    setColor(12);
    gotoXY(sx, 17); printf("  *  = Food");
    setColor(7);
}

/* 生成食物（避免放在蛇身上） */
static void spawnFood(void) {
    int ok;
    do {
        ok = 1;
        food.x = rand() % W + 1;
        food.y = rand() % H + 1;
        for (int i = 0; i < sLen; i++)
            if (snake[i].x == food.x && snake[i].y == food.y) { ok = 0; break; }
    } while (!ok);
    putAt(food.x, food.y, 12, '*');  /* 红色 * */
}

/* 绘制整条蛇 */
static void drawSnake(void) {
    putAt(snake[0].x, snake[0].y, 10, '@');  /* 亮绿色蛇头 */
    for (int i = 1; i < sLen; i++)
        putAt(snake[i].x, snake[i].y, 2, 'o');  /* 暗绿色蛇身 */
}

/* ════════════════════════════════════════════════════════
   游戏逻辑
   ════════════════════════════════════════════════════════ */
static void initGame(void) {
    sLen     = 4;
    dir      = RIGHT;
    score    = 0;
    gameOver = 0;
    speed    = 160;

    /* 蛇从中央向右排列 */
    for (int i = 0; i < sLen; i++) {
        snake[i].x = W / 2 - i;
        snake[i].y = H / 2;
    }

    system("cls");
    drawBorder();
    drawSnake();
    spawnFood();
    drawSidebar();
}

/* 处理键盘输入，返回 0=正常, 非0=退出标志 */
static void handleInput(void) {
    if (!_kbhit()) return;
    int k = _getch();

    if (k == 0 || k == 224) {     /* 方向键前导字节 */
        k = _getch();
        switch (k) {
            case 72: if (dir != DOWN)  dir = UP;    break;  /* ↑ */
            case 80: if (dir != UP)    dir = DOWN;  break;  /* ↓ */
            case 75: if (dir != RIGHT) dir = LEFT;  break;  /* ← */
            case 77: if (dir != LEFT)  dir = RIGHT; break;  /* → */
        }
        return;
    }

    switch (k) {
        case 'w': case 'W': if (dir != DOWN)  dir = UP;    break;
        case 's': case 'S': if (dir != UP)    dir = DOWN;  break;
        case 'a': case 'A': if (dir != RIGHT) dir = LEFT;  break;
        case 'd': case 'D': if (dir != LEFT)  dir = RIGHT; break;

        case 'p': case 'P': {
            /* 暂停 */
            int px = W / 2 - 4, py = H / 2;
            setColor(15);
            gotoXY(px, py);   printf("[ PAUSED ]");
            gotoXY(px, py+1); printf(" P:Resume ");
            gotoXY(px, py+2); printf(" ESC:Quit ");
            setColor(7);
            int pk;
            do {
                pk = _getch();
                if (pk == 0 || pk == 224) pk = _getch();
            } while (pk != 'p' && pk != 'P' && pk != 27);
            if (pk == 27) { gameOver = 2; return; }
            /* 清除暂停提示并重绘 */
            for (int i = py; i <= py + 2; i++) {
                gotoXY(px, i); printf("          ");
            }
            /* 重绘食物和蛇（简单方案：刷新整个游戏区） */
            drawSnake();
            putAt(food.x, food.y, 12, '*');
            break;
        }

        case 27:  /* ESC */
            gameOver = 2;
            break;
    }
}

static void update(void) {
    Point tail = snake[sLen - 1];

    /* 蛇身整体后移 */
    for (int i = sLen - 1; i > 0; i--) snake[i] = snake[i - 1];

    /* 蛇头移动 */
    switch (dir) {
        case UP:    snake[0].y--; break;
        case DOWN:  snake[0].y++; break;
        case LEFT:  snake[0].x--; break;
        case RIGHT: snake[0].x++; break;
    }

    /* 碰墙检测 */
    if (snake[0].x < 1 || snake[0].x > W ||
        snake[0].y < 1 || snake[0].y > H) {
        gameOver = 1; return;
    }

    /* 碰自身检测 */
    for (int i = 1; i < sLen; i++) {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
            gameOver = 1; return;
        }
    }

    /* 吃到食物 */
    if (snake[0].x == food.x && snake[0].y == food.y) {
        sLen++;
        score += 10;
        if (score > highScore) highScore = score;
        /* 随分数加速，最快 60 ms */
        speed = 160 - (score / 50) * 15;
        if (speed < 60) speed = 60;
        spawnFood();
        drawSidebar();
    } else {
        /* 只擦掉尾巴 */
        clearAt(tail.x, tail.y);
    }

    drawSnake();
}

/* ════════════════════════════════════════════════════════
   游戏结束画面
   ════════════════════════════════════════════════════════ */
static void showGameOver(void) {
    int cx = (W + 2) / 2 - 7;
    int cy = H / 2 - 2;

    /* 红色边框 */
    setColor(12);
    gotoXY(cx,     cy);   printf("+--------------+");
    gotoXY(cx,     cy+1); printf("|  GAME  OVER  |");
    gotoXY(cx,     cy+2); printf("+--------------+");
    setColor(14);
    gotoXY(cx,     cy+3); printf("| Score :%5d  |", score);
    gotoXY(cx,     cy+4); printf("| Best  :%5d  |", highScore);
    setColor(7);
    gotoXY(cx,     cy+5); printf("+--------------+");
    gotoXY(cx,     cy+6); printf("  P - Retry  ");
    gotoXY(cx,     cy+7); printf("  ESC - Quit ");
    setColor(7);
}

/* ════════════════════════════════════════════════════════
   主函数
   ════════════════════════════════════════════════════════ */
int main(void) {
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleOutputCP(936);
    SetConsoleTitle("Snake Game - 贪吃蛇");
    system("mode con cols=62 lines=24");
    hideCursor();
    srand((unsigned)time(NULL));

    for (;;) {
        initGame();

        while (!gameOver) {
            handleInput();
            if (gameOver) break;
            update();
            Sleep(speed);
        }

        if (gameOver == 2) break;   /* ESC 退出 */

        showGameOver();

        /* 等待玩家决定 */
        for (;;) {
            int k = _getch();
            if (k == 0 || k == 224) { _getch(); continue; }
            if (k == 27) goto quit;  /* ESC */
            if (k == 'p' || k == 'P') break; /* 重玩 */
        }
    }

quit:
    showCursor();
    system("cls");
    setColor(11);
    printf("\n  感谢游玩贪吃蛇!\n");
    setColor(14);
    printf("  最终得分: %d\n", score);
    printf("  最高记录: %d\n\n", highScore);
    setColor(7);
    system("pause");
    return 0;
}
