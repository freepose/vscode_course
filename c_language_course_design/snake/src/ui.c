#include "ui.h"

void DrawHUD(int score, int bestScore, int autoMode, const char *modeLabel) {
    DrawRectangle(0, 0, GetScreenWidth(), GRID_OFFSET_Y - 10, (Color){25, 25, 30, 255});

    const char *title = "[ SNAKE ]";
    int titleW = MeasureText(title, 28);
    DrawText(title, (GetScreenWidth() - titleW) / 2, 12, 28, GREEN);

    char scoreText[64];
    snprintf(scoreText, sizeof(scoreText), "Score: %d", score);
    DrawText(scoreText, GRID_OFFSET_X, 18, 20, RAYWHITE);

    char bestText[64];
    snprintf(bestText, sizeof(bestText), "Best: %d", bestScore);
    DrawText(bestText, GRID_OFFSET_X + 200, 18, 20, GOLD);

    Color modeCol = (autoMode) ? SKYBLUE : LIGHTGRAY;
    DrawText(modeLabel, GetScreenWidth() - GRID_OFFSET_X - MeasureText(modeLabel, 20), 18, 20, modeCol);

    DrawText("SPACE: Pause | A: Cycle Mode | R: Restart | ESC: Quit",
             GRID_OFFSET_X, 38, 16, (Color){120, 120, 120, 255});
}

void DrawCell(int x, int y, Color col, int glow) {
    int px = GRID_OFFSET_X + x * CELL_SIZE;
    int py = GRID_OFFSET_Y + y * CELL_SIZE;

    if (glow) {
        DrawRectangle(px + 1, py + 1, CELL_SIZE - 2, CELL_SIZE - 2,
                     (Color){col.r, col.g, col.b, 80});
    }
    DrawRectangle(px + 2, py + 2, CELL_SIZE - 4, CELL_SIZE - 4, col);
}

void DrawSnakeCells(int *snakeXArr, int *snakeYArr, int snakeLen) {
    for (int i = snakeLen - 1; i >= 0; i--) {
        Color col;
        if (i == 0) {
            col = SnakeHeadColor;
        } else {
            int t = (i * 200) / snakeLen;
            col = (Color){0, (unsigned char)(150 + t), 0, 255};
        }
        DrawCell(snakeXArr[i], snakeYArr[i], col, i == 0);
    }
}

void DrawGameGrid(int grid[GRID_H][GRID_W]) {
    for (int y = 0; y < GRID_H; y++) {
        for (int x = 0; x < GRID_W; x++) {
            int px = GRID_OFFSET_X + x * CELL_SIZE;
            int py = GRID_OFFSET_Y + y * CELL_SIZE;

            DrawRectangleLines(px, py, CELL_SIZE, CELL_SIZE,
                              (Color){35, 35, 40, 255});

            if (grid[y][x] == 1) {
                DrawCell(x, y, WallColor, 0);
            }
        }
    }
}

void DrawFood(int fx, int fy) {
    int px = GRID_OFFSET_X + fx * CELL_SIZE;
    int py = GRID_OFFSET_Y + fy * CELL_SIZE;
    Vector2 center = {(float)px + CELL_SIZE / 2.0f, (float)py + CELL_SIZE / 2.0f};
    float r = (float)CELL_SIZE / 2.5f;
    DrawCircleLines((int)center.x, (int)center.y, r, FoodColor);
    DrawCircle((int)center.x, (int)center.y, r * 0.6f, FoodColor);
}

void DrawGameOver(int score, int bestScore) {
    int w = GetScreenWidth();
    int h = GetScreenHeight();

    DrawRectangle(0, 0, w, h, (Color){0, 0, 0, 180});

    const char *title = "GAME OVER";
    int titleW = MeasureText(title, 50);
    DrawText(title, (w - titleW) / 2, h / 2 - 80, 50, RED);

    char scoreText[64];
    snprintf(scoreText, sizeof(scoreText), "Score: %d", score);
    int sw = MeasureText(scoreText, 28);
    DrawText(scoreText, (w - sw) / 2, h / 2 - 20, 28, RAYWHITE);

    char bestText[64];
    snprintf(bestText, sizeof(bestText), "Best: %d", bestScore);
    int bw = MeasureText(bestText, 28);
    DrawText(bestText, (w - bw) / 2, h / 2 + 20, 28, GOLD);

    const char *hint = "Press R to Restart  or  ESC to Quit";
    int hw = MeasureText(hint, 20);
    DrawText(hint, (w - hw) / 2, h / 2 + 70, 20, LIGHTGRAY);
}

void DrawMenu(void) {
    ClearBackground((Color){15, 15, 20, 255});

    const char *title = "[ SNAKE ]";
    int titleW = MeasureText(title, 50);
    DrawText(title, (GetScreenWidth() - titleW) / 2, 60, 50, GREEN);

    const char *subtitle = "Raylib Game  |  3 Auto Modes";
    int subW = MeasureText(subtitle, 22);
    DrawText(subtitle, (GetScreenWidth() - subW) / 2, 120, 22, LIGHTGRAY);

    const char *opts[] = {
        "1 - Play (Manual)",
        "2 - Play (Auto Greedy BFS)",
        "3 - Play (Auto Hamilton Cycle)",
    };
    for (int i = 0; i < 3; i++) {
        int ow = MeasureText(opts[i], 24);
        DrawText(opts[i], (GetScreenWidth() - ow) / 2, 180 + i * 50, 24, RAYWHITE);
    }

    DrawText("In-game: press A to cycle through modes",
             (GetScreenWidth() - MeasureText("In-game: press A to cycle through modes", 18)) / 2,
             380, 18, (Color){80, 80, 80, 255});

    const char *hint = "ESC - Quit";
    int hw = MeasureText(hint, 18);
    DrawText(hint, (GetScreenWidth() - hw) / 2, 430, 18, (Color){100, 100, 100, 255});
}

void DrawGame(int grid[GRID_H][GRID_W], int snakeX, int snakeY,
              int snakeLen, int *snakeXArr, int *snakeYArr,
              int foodX, int foodY, int score, int bestScore,
              int gameOver, PlayMode playMode, const char *modeLabel) {
    (void)snakeX;
    (void)snakeY;
    ClearBackground((Color){15, 15, 20, 255});
    int isAuto = (playMode != MODE_MANUAL);
    DrawHUD(score, bestScore, isAuto, modeLabel);
    DrawGameGrid(grid);
    DrawSnakeCells(snakeXArr, snakeYArr, snakeLen);
    DrawFood(foodX, foodY);

    if (gameOver) {
        DrawGameOver(score, bestScore);
    }
}
