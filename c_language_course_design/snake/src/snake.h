#ifndef SNAKE_H
#define SNAKE_H

#include <stdlib.h>

#define GRID_W  30
#define GRID_H  22

#define CELL_W  24
#define CELL_H  24

#define SPEED   10

typedef struct {
    int x, y;
} Cell;

typedef enum {
    STATE_MENU,
    STATE_PLAYING,
    STATE_PAUSED,
    STATE_GAMEOVER
} GameState;

typedef enum {
    MODE_MANUAL,
    MODE_AUTO_GREEDY,
    MODE_AUTO_HAMILTON
} PlayMode;

typedef struct {
    Cell body[GRID_W * GRID_H];
    int len;
    int dir;
} Snake;

typedef struct {
    int x;
    int y;
} Food;

typedef struct {
    Snake snake;
    Food food;
    int grid[GRID_H][GRID_W];
    int score;
    int bestScore;
    GameState state;
    PlayMode playMode;
    int frameCounter;
    int moveInterval;
} Game;

void InitGame(Game *g);
void ResetGame(Game *g);
void UpdateGame(Game *g);
void MoveSnake(Game *g);
void SpawnFood(Game *g);
int  IsCollision(Game *g);
int  IsWall(int x, int y);
int  IsInSnakeBody(Game *g, int x, int y);
void InputHandle(Game *g);
void SetDirection(Game *g, int newDir);

#endif // SNAKE_H
