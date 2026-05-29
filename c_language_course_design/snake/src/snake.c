#include "snake.h"
#include "ui.h"
#include "auto.h"
#include "raylib.h"
#include <time.h>

#define FOOD_SCORE 10

static int dirX[4] = {0, 0, -1, 1};
static int dirY[4] = {-1, 1, 0, 0};

static int bestScore = 0;

static int snakeXArr[GRID_W * GRID_H];
static int snakeYArr[GRID_W * GRID_H];

static int pendingDir = -1;

static Game game;

int IsInSnakeBody(Game *g, int x, int y) {
    for (int i = 0; i < g->snake.len; i++) {
        if (g->snake.body[i].x == x && g->snake.body[i].y == y)
            return 1;
    }
    return 0;
}

void InitGame(Game *g) {
    g->state = STATE_MENU;
    g->playMode = MODE_MANUAL;
    g->score = 0;
    g->snake.len = 3;
    g->snake.dir = DIR_RIGHT;

    int sx = GRID_W / 2;
    int sy = GRID_H / 2;
    for (int i = 0; i < g->snake.len; i++) {
        g->snake.body[i].x = sx - i;
        g->snake.body[i].y = sy;
        snakeXArr[i] = sx - i;
        snakeYArr[i] = sy;
    }

    for (int y = 0; y < GRID_H; y++)
        for (int x = 0; x < GRID_W; x++)
            g->grid[y][x] = 0;

    g->food.x = sx + 5;
    g->food.y = sy;
    g->frameCounter = 0;
    g->moveInterval = (int)(GetFrameTime() > 0 ? 1.0 / 0.12 : 1);
}

void ResetGame(Game *g) {
    g->score = 0;
    g->snake.len = 3;
    g->snake.dir = DIR_RIGHT;
    g->frameCounter = 0;

    int sx = GRID_W / 2;
    int sy = GRID_H / 2;
    for (int i = 0; i < g->snake.len; i++) {
        g->snake.body[i].x = sx - i;
        g->snake.body[i].y = sy;
        snakeXArr[i] = sx - i;
        snakeYArr[i] = sy;
    }

    for (int y = 0; y < GRID_H; y++)
        for (int x = 0; x < GRID_W; x++)
            g->grid[y][x] = 0;

    SpawnFood(g);
    pendingDir = -1;

    if (g->playMode == MODE_AUTO_HAMILTON) {
        hamiltonReset();
        hamiltonPrecompute();
    }
}

void SpawnFood(Game *g) {
    int count = 0;
    for (int y = 0; y < GRID_H; y++)
        for (int x = 0; x < GRID_W; x++)
            if (!g->grid[y][x] && !IsInSnakeBody(g, x, y))
                count++;

    if (count == 0) return;

    int idx = GetRandomValue(0, count - 1);
    count = 0;
    for (int y = 0; y < GRID_H; y++) {
        for (int x = 0; x < GRID_W; x++) {
            if (!g->grid[y][x] && !IsInSnakeBody(g, x, y)) {
                if (count == idx) {
                    g->food.x = x;
                    g->food.y = y;
                    return;
                }
                count++;
            }
        }
    }
}

void SetDirection(Game *g, int newDir) {
    int opposite[4] = {DIR_DOWN, DIR_UP, DIR_RIGHT, DIR_LEFT};
    if (newDir >= 0 && newDir < 4 && newDir != opposite[g->snake.dir])
        pendingDir = newDir;
}

/* Cycle play mode: MANUAL -> GREEDY -> HAMILTON -> MANUAL ... */
static PlayMode cycleMode(PlayMode m) {
    if (m == MODE_MANUAL)       return MODE_AUTO_GREEDY;
    if (m == MODE_AUTO_GREEDY)  return MODE_AUTO_HAMILTON;
    return MODE_MANUAL;
}

void InputHandle(Game *g) {
    if (g->state == STATE_MENU) {
        if (IsKeyPressed(KEY_ONE)) {
            g->playMode = MODE_MANUAL;
            ResetGame(g);
            g->state = STATE_PLAYING;
        }
        if (IsKeyPressed(KEY_TWO)) {
            g->playMode = MODE_AUTO_GREEDY;
            hamiltonReset();
            ResetGame(g);
            g->state = STATE_PLAYING;
        }
        if (IsKeyPressed(KEY_THREE)) {
            g->playMode = MODE_AUTO_HAMILTON;
            hamiltonPrecompute();
            ResetGame(g);
            g->state = STATE_PLAYING;
        }
        if (IsKeyPressed(KEY_ESCAPE)) {
            CloseWindow();
        }
        return;
    }

    if (g->state == STATE_GAMEOVER) {
        if (IsKeyPressed(KEY_R)) {
            ResetGame(g);
            g->state = STATE_PLAYING;
        }
        if (IsKeyPressed(KEY_ESCAPE)) {
            CloseWindow();
        }
        return;
    }

    if (g->state == STATE_PAUSED) {
        if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_P)) {
            g->state = STATE_PLAYING;
        }
        if (IsKeyPressed(KEY_ESCAPE)) {
            CloseWindow();
        }
        return;
    }

    if (g->state == STATE_PLAYING) {
        if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_P)) {
            g->state = STATE_PAUSED;
            return;
        }
        if (IsKeyPressed(KEY_A)) {
            g->playMode = cycleMode(g->playMode);
            if (g->playMode == MODE_AUTO_HAMILTON) {
                hamiltonReset();
                hamiltonPrecompute();
            }
            return;
        }
        if (IsKeyPressed(KEY_R)) {
            ResetGame(g);
            return;
        }
        if (IsKeyPressed(KEY_ESCAPE)) {
            CloseWindow();
            return;
        }

        if (g->playMode == MODE_MANUAL) {
            if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W))
                SetDirection(g, DIR_UP);
            else if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S))
                SetDirection(g, DIR_DOWN);
            else if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A))
                SetDirection(g, DIR_LEFT);
            else if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D))
                SetDirection(g, DIR_RIGHT);
        }
    }
}

void MoveSnake(Game *g) {
    if (g->playMode == MODE_AUTO_GREEDY) {
        int autoDir = getAutoDirection(g->grid, snakeXArr, snakeYArr,
                                        g->snake.len, g->food.x, g->food.y);
        SetDirection(g, autoDir);
    } else if (g->playMode == MODE_AUTO_HAMILTON) {
        int autoDir = getHamiltonDirection(snakeXArr, snakeYArr,
                                            g->snake.len, g->food.x, g->food.y);
        SetDirection(g, autoDir);
    }

    if (pendingDir != -1) {
        g->snake.dir = pendingDir;
        pendingDir = -1;
    }

    int newX = g->snake.body[0].x + dirX[g->snake.dir];
    int newY = g->snake.body[0].y + dirY[g->snake.dir];

    if (newX < 0 || newX >= GRID_W || newY < 0 || newY >= GRID_H) {
        g->state = STATE_GAMEOVER;
        if (g->score > bestScore) bestScore = g->score;
        return;
    }

    for (int i = 0; i < g->snake.len; i++) {
        if (g->snake.body[i].x == newX && g->snake.body[i].y == newY) {
            g->state = STATE_GAMEOVER;
            if (g->score > bestScore) bestScore = g->score;
            return;
        }
    }

    if (g->grid[newY][newX] == 1) {
        g->state = STATE_GAMEOVER;
        if (g->score > bestScore) bestScore = g->score;
        return;
    }

    for (int i = g->snake.len - 1; i > 0; i--) {
        g->snake.body[i] = g->snake.body[i - 1];
    }
    g->snake.body[0].x = newX;
    g->snake.body[0].y = newY;

    for (int i = 0; i < g->snake.len; i++) {
        snakeXArr[i] = g->snake.body[i].x;
        snakeYArr[i] = g->snake.body[i].y;
    }

    if (newX == g->food.x && newY == g->food.y) {
        g->snake.len++;
        g->score += FOOD_SCORE;

        for (int i = g->snake.len - 1; i > 0; i--) {
            g->snake.body[i] = g->snake.body[i - 1];
        }
        g->snake.body[0].x = newX;
        g->snake.body[0].y = newY;

        for (int i = 0; i < g->snake.len; i++) {
            snakeXArr[i] = g->snake.body[i].x;
            snakeYArr[i] = g->snake.body[i].y;
        }

        SpawnFood(g);
    }

    snakeXArr[g->snake.len] = snakeXArr[g->snake.len - 1];
    snakeYArr[g->snake.len] = snakeYArr[g->snake.len - 1];
}

void UpdateGame(Game *g) {
    if (g->state != STATE_PLAYING) return;

    g->frameCounter++;

    int speed = SPEED;
    if (g->playMode == MODE_AUTO_GREEDY)
        speed = 10;
    if (g->playMode == MODE_AUTO_HAMILTON)
        speed = 60;

    if (g->frameCounter >= 60 / speed) {
        g->frameCounter = 0;
        MoveSnake(g);
    }
}

/* Return a mode label string for UI */
static const char *modeLabel(PlayMode m) {
    if (m == MODE_MANUAL)       return "[ MANUAL ]";
    if (m == MODE_AUTO_GREEDY)  return "[ GREEDY ]";
    return "[ HAMILTON ]";
}

int main(void) {
    SetRandomSeed((unsigned int)time(NULL));

    int scrW = GRID_OFFSET_X * 2 + GRID_W * CELL_SIZE;
    int scrH = GRID_OFFSET_Y * 2 + GRID_H * CELL_SIZE + 20;
    InitWindow(scrW, scrH, "Snake - Raylib");
    SetTargetFPS(60);

    InitGame(&game);

    while (!WindowShouldClose()) {
        InputHandle(&game);
        UpdateGame(&game);

        BeginDrawing();
        {
            if (game.state == STATE_MENU) {
                DrawMenu();
            } else {
                DrawGame(game.grid,
                         game.snake.body[0].x, game.snake.body[0].y,
                         game.snake.len,
                         snakeXArr, snakeYArr,
                         game.food.x, game.food.y,
                         game.score, bestScore,
                         game.state == STATE_GAMEOVER,
                         game.playMode,
                         modeLabel(game.playMode));

                if (game.state == STATE_PAUSED) {
                    int w = GetScreenWidth();
                    int h = GetScreenHeight();
                    DrawRectangle(0, 0, w, h, (Color){0, 0, 0, 150});
                    const char *msg = "PAUSED - Press SPACE to Resume";
                    int mw = MeasureText(msg, 24);
                    DrawText(msg, (w - mw) / 2, h / 2 - 12, 24, RAYWHITE);
                }
            }
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
