#ifndef SNAKE_UI_H
#define SNAKE_UI_H

#include "raylib.h"
#include <stdio.h>
#include "snake.h"

#define CELL_SIZE     24
#define GRID_W         30
#define GRID_H         22
#define GRID_OFFSET_X  20
#define GRID_OFFSET_Y  60

#define UIColor BGRAY
#define GridColor (Color){30, 30, 30, 255}
#define SnakeHeadColor DARKGREEN
#define SnakeBodyColor GREEN
#define FoodColor RED
#define WallColor (Color){80, 80, 80, 255}

void DrawGameGrid(int grid[GRID_H][GRID_W]);
void DrawSnakeCells(int *snakeXArr, int *snakeYArr, int snakeLen);
void DrawCell(int x, int y, Color col, int glow);
void DrawHUD(int score, int bestScore, int autoMode, const char *modeLabel);
void DrawMenu(void);
void DrawGameOver(int score, int bestScore);
void DrawGame(int grid[GRID_H][GRID_W], int snakeX, int snakeY,
              int snakeLen, int *snakeXArr, int *snakeYArr,
              int foodX, int foodY, int score, int bestScore,
              int gameOver, PlayMode playMode, const char *modeLabel);

#endif // SNAKE_UI_H
