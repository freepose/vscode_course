#ifndef SNAKE_AUTO_H
#define SNAKE_AUTO_H

#include "snake.h"

typedef enum {
    DIR_UP,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT
} Direction;

typedef struct {
    int x, y;
} Point;

int isValidMove(int grid[GRID_H][GRID_W], int x, int y,
                int *snakeXArr, int *snakeYArr, int snakeLen);
int isInSnake(int x, int y, int *snakeXArr, int *snakeYArr, int snakeLen);
int bfs(int grid[GRID_H][GRID_W], int sx, int sy, int tx, int ty,
        int *snakeXArr, int *snakeYArr, int snakeLen);
int getAutoDirection(int grid[GRID_H][GRID_W], int *snakeXArr, int *snakeYArr, int snakeLen, int foodX, int foodY);
int willHitBody(int x, int y, int *snakeXArr, int *snakeYArr, int snakeLen);
int isSpace(int grid[GRID_H][GRID_W], int x, int y);
int countReachable(int grid[GRID_H][GRID_W], int sx, int sy,
                   int *snakeXArr, int *snakeYArr, int snakeLen);

/* Hamilton cycle */
int  hamiltonPrecompute(void);
int  getHamiltonDirection(int *snakeXArr, int *snakeYArr, int snakeLen, int foodX, int foodY);
void hamiltonReset(void);

#endif // SNAKE_AUTO_H
