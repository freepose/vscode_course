#include "auto.h"
#include "snake.h"
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define QUEUE_SIZE (GRID_W * GRID_H)

static int visited[GRID_H][GRID_W];
static Point queue[QUEUE_SIZE];

static int dirs[4][2] = {
    {-1, 0},
    { 1, 0},
    { 0,-1},
    { 0, 1}
};

/* =====================================================================
   Greedy BFS Auto (MODE_AUTO_GREEDY)
   ===================================================================== */

int isInSnake(int x, int y, int *snakeXArr, int *snakeYArr, int snakeLen) {
    for (int i = 0; i < snakeLen; i++) {
        if (snakeXArr[i] == x && snakeYArr[i] == y)
            return 1;
    }
    return 0;
}

int isValidMove(int grid[GRID_H][GRID_W], int x, int y,
                int *snakeXArr, int *snakeYArr, int snakeLen) {
    if (x < 0 || x >= GRID_W || y < 0 || y >= GRID_H)
        return 0;
    if (grid[y][x] == 1)
        return 0;
    return !isInSnake(x, y, snakeXArr, snakeYArr, snakeLen);
}

int willHitBody(int x, int y,
                int *snakeXArr, int *snakeYArr, int snakeLen) {
    return isInSnake(x, y, snakeXArr, snakeYArr, snakeLen);
}

int isSpace(int grid[GRID_H][GRID_W], int x, int y) {
    if (x < 0 || x >= GRID_W || y < 0 || y >= GRID_H)
        return 0;
    return grid[y][x] == 0;
}

int countReachable(int grid[GRID_H][GRID_W], int sx, int sy,
                   int *snakeXArr, int *snakeYArr, int snakeLen) {
    memset(visited, 0, sizeof(visited));
    int head = 0, tail = 0;

    visited[sy][sx] = 1;
    queue[tail++] = (Point){sx, sy};

    int count = 0;
    while (head < tail) {
        Point p = queue[head++];
        count++;

        for (int i = 0; i < 4; i++) {
            int nx = p.x + dirs[i][0];
            int ny = p.y + dirs[i][1];
            if (nx >= 0 && nx < GRID_W && ny >= 0 && ny < GRID_H &&
                !visited[ny][nx] && isValidMove(grid, nx, ny, snakeXArr, snakeYArr, snakeLen)) {
                visited[ny][nx] = 1;
                queue[tail++] = (Point){nx, ny};
            }
        }
    }
    return count;
}

int bfs(int grid[GRID_H][GRID_W], int sx, int sy, int tx, int ty,
        int *snakeXArr, int *snakeYArr, int snakeLen) {
    if (sx == tx && sy == ty) return 1;

    memset(visited, 0, sizeof(visited));
    int head = 0, tail = 0;

    visited[sy][sx] = 1;
    queue[tail++] = (Point){sx, sy};

    while (head < tail) {
        Point p = queue[head++];
        if (p.x == tx && p.y == ty) return 1;

        for (int i = 0; i < 4; i++) {
            int nx = p.x + dirs[i][0];
            int ny = p.y + dirs[i][1];
            if (nx >= 0 && nx < GRID_W && ny >= 0 && ny < GRID_H &&
                !visited[ny][nx] && isValidMove(grid, nx, ny, snakeXArr, snakeYArr, snakeLen)) {
                visited[ny][nx] = 1;
                queue[tail++] = (Point){nx, ny};
            }
        }
    }
    return 0;
}

int getAutoDirection(int grid[GRID_H][GRID_W], int *snakeXArr, int *snakeYArr, int snakeLen, int foodX, int foodY) {
    int sx = snakeXArr[0];
    int sy = snakeYArr[0];

    int baseDirs[4][2] = {
        { 0, -1},
        { 0,  1},
        {-1,  0},
        { 1,  0}
    };
    int opposite[4] = {1, 0, 3, 2};

    int currentDir = 0;
    int nx0 = snakeXArr[1];
    int ny0 = snakeYArr[1];
    for (int i = 0; i < 4; i++) {
        int tx = sx + baseDirs[i][0];
        int ty = sy + baseDirs[i][1];
        if (tx == nx0 && ty == ny0) {
            currentDir = i;
            break;
        }
    }

    int bestDir = currentDir;
    int bestScore = INT_MIN;

    for (int i = 0; i < 4; i++) {
        if (i == opposite[currentDir])
            continue;

        int mx = sx + baseDirs[i][0];
        int my = sy + baseDirs[i][1];

        if (!isValidMove(grid, mx, my, snakeXArr, snakeYArr, snakeLen))
            continue;

        int newHeadX = mx;
        int newHeadY = my;
        int oldTailX = snakeXArr[snakeLen - 1];
        int oldTailY = snakeYArr[snakeLen - 1];
        int newSnakeLen = (mx == foodX && my == foodY) ? snakeLen + 1 : snakeLen;

        int gridCopy[GRID_H][GRID_W];
        memcpy(gridCopy, grid, sizeof(gridCopy));

        gridCopy[newHeadY][newHeadX] = 1;
        if (!(mx == foodX && my == foodY)) {
            gridCopy[oldTailY][oldTailX] = 0;
        }

        int reachable = countReachable(gridCopy, newHeadX, newHeadY, snakeXArr, snakeYArr, newSnakeLen);

        int score = 0;

        if (mx == foodX && my == foodY) {
            score += 10000;
        } else {
            int canReachFood = bfs(gridCopy, newHeadX, newHeadY, foodX, foodY, snakeXArr, snakeYArr, newSnakeLen);
            if (canReachFood) {
                score += 500;
            }
            int dist = abs(mx - foodX) + abs(my - foodY);
            score -= dist * 5;
        }

        score += reachable * 10;

        if (reachable < 3) {
            score -= 5000;
        }

        if (reachable >= newSnakeLen) {
            score += 2000;
        }

        if (score > bestScore) {
            bestScore = score;
            bestDir = i;
        }
    }

    return bestDir;
}

/* =====================================================================
   Hamiltonian Cycle Auto (MODE_AUTO_HAMILTON)

   Grid layout (zigzag, works for even GRID_W):

     Row 0:  (0,0)→(1,0)→...→(29,0)
     Row 1:  (29,1)←(28,1)←...←(0,1)
     ...

   The snake follows this cycle. When food appears, it takes the shorter
   path along the cycle toward food. Since the cycle visits every cell
   exactly once, the snake can always traverse the entire grid without
   colliding with itself — it just needs to stay on the cycle.

   Key insight: the tail cell is ALWAYS the cell just vacated by the head,
   so it can never block the head's movement. Only the body (excluding tail)
   can block. The algorithm checks forward/backward on the cycle and picks
   the direction that leads toward food, with greedy fallback only when
   both cycle directions are blocked.
   ===================================================================== */

static int hamOrder[GRID_H][GRID_W];
static int hamIndex[GRID_H][GRID_W];
static int hamReady = 0;

int hamiltonPrecompute(void) {
    int idx = 0;
    for (int y = 0; y < GRID_H; y++) {
        if (y % 2 == 0) {
            for (int x = 0; x < GRID_W; x++) {
                hamOrder[y][x] = idx;
                hamIndex[y][x] = idx;
                idx++;
            }
        } else {
            for (int x = GRID_W - 1; x >= 0; x--) {
                hamOrder[y][x] = idx;
                hamIndex[y][x] = idx;
                idx++;
            }
        }
    }
    hamReady = 1;
    return idx;
}

void hamiltonReset(void) {
    hamReady = 0;
}

/* Convert cycle order k to (x,y) */
static void hamKth(int k, int *outX, int *outY) {
    int n = GRID_W * GRID_H;
    k = ((k % n) + n) % n;
    for (int y = 0; y < GRID_H; y++) {
        int cellsInRow = GRID_W;
        if (k < cellsInRow) {
            if (y % 2 == 0) {
                *outX = k;
            } else {
                *outX = GRID_W - 1 - k;
            }
            *outY = y;
            return;
        }
        k -= cellsInRow;
    }
    *outX = 0; *outY = 0;
}

/* Cycle order of (x,y) */
static int hamOrderOf(int x, int y) {
    return hamIndex[y][x];
}

/* Next/prev cell on the cycle */
static void hamNext(int x, int y, int *outX, int *outY) {
    int k = hamOrderOf(x, y);
    hamKth(k + 1, outX, outY);
}

static void hamPrev(int x, int y, int *outX, int *outY) {
    int k = hamOrderOf(x, y);
    hamKth(k - 1, outX, outY);
}

/* Direction index from (sx,sy) to (tx,ty) */
static int dirFromTo(int sx, int sy, int tx, int ty) {
    if (ty < sy) return 0; /* UP    */
    if (ty > sy) return 1; /* DOWN  */
    if (tx < sx) return 2; /* LEFT  */
    if (tx > sx) return 3; /* RIGHT */
    return 0;
}

/* Build a safety grid: body cells (EXCLUDING tail, since tail moves)
   marked as blocked. Tail cell is always free (will be vacated). */
static void buildSafetyGrid(int grid[GRID_H][GRID_W],
                            int *snakeXArr, int *snakeYArr, int snakeLen,
                            int foodX, int foodY) {
    for (int y = 0; y < GRID_H; y++)
        for (int x = 0; x < GRID_W; x++)
            grid[y][x] = grid[y][x]; /* walls preserved */

    /* Body cells excluding the tail — the tail will vacate next move */
    for (int i = 0; i < snakeLen - 1; i++) {
        grid[snakeYArr[i]][snakeXArr[i]] = 1;
    }
    /* Food position is also blocked */
    grid[foodY][foodX] = 1;
}

/* Count reachable cells from (sx,sy) on the given safety grid */
static int countReachableOn(int grid[GRID_H][GRID_W], int sx, int sy,
                            int *snakeXArr, int *snakeYArr, int snakeLen) {
    memset(visited, 0, sizeof(visited));
    int head = 0, tail = 0;

    visited[sy][sx] = 1;
    queue[tail++] = (Point){sx, sy};

    int count = 0;
    while (head < tail) {
        Point p = queue[head++];
        count++;
        for (int i = 0; i < 4; i++) {
            int nx = p.x + dirs[i][0];
            int ny = p.y + dirs[i][1];
            if (nx >= 0 && nx < GRID_W && ny >= 0 && ny < GRID_H &&
                !visited[ny][nx] && !grid[ny][nx] &&
                !isInSnake(nx, ny, snakeXArr, snakeYArr, snakeLen)) {
                visited[ny][nx] = 1;
                queue[tail++] = (Point){nx, ny};
            }
        }
    }
    return count;
}

static int oppositeDir(int d) {
    return 3 - d;
}

int getHamiltonDirection(int *snakeXArr, int *snakeYArr, int snakeLen, int foodX, int foodY) {
    if (!hamReady) {
        hamiltonPrecompute();
    }

    int sx = snakeXArr[0];
    int sy = snakeYArr[0];

    int n = GRID_W * GRID_H;
    int curOrder  = hamOrderOf(sx, sy);
    int foodOrder = hamOrderOf(foodX, foodY);

    /* Forward / backward distance along the cycle */
    int distFwd  = (foodOrder - curOrder + n) % n;
    int distBack = (curOrder - foodOrder + n) % n;

    /* Build safety grid: tail excluded from blocked set */
    int safetyGrid[GRID_H][GRID_W] = {0};
    for (int y = 0; y < GRID_H; y++)
        for (int x = 0; x < GRID_W; x++)
            safetyGrid[y][x] = 0;
    buildSafetyGrid(safetyGrid, snakeXArr, snakeYArr, snakeLen, foodX, foodY);

    /*
     * Strategy:
     *  1. If food is right next to head (adjacent), eat it directly.
     *  2. Choose the shorter direction along the cycle (fwd or back).
     *  3. If that direction is blocked by body, try the opposite.
     *  4. If both directions blocked, fall back to greedy.
     *  5. Only move if it leaves enough reachable space (safety check).
     */
    if ((abs(foodX - sx) + abs(foodY - sy)) == 1) {
        return dirFromTo(sx, sy, foodX, foodY);
    }

    /* Forward cycle cell */
    int fwdX, fwdY;
    hamNext(sx, sy, &fwdX, &fwdY);
    int fwdBlocked = safetyGrid[fwdY][fwdX];

    /* Backward cycle cell */
    int backX, backY;
    hamPrev(sx, sy, &backX, &backY);
    int backBlocked = safetyGrid[backY][backX];

    int targetX, targetY;

    if (distFwd <= distBack && !fwdBlocked) {
        /* Food is ahead (or equal), go forward */
        targetX = fwdX; targetY = fwdY;
    } else if (distBack < distFwd && !backBlocked) {
        /* Food is behind, go backward */
        targetX = backX; targetY = backY;
    } else if (!fwdBlocked) {
        targetX = fwdX; targetY = fwdY;
    } else if (!backBlocked) {
        targetX = backX; targetY = backY;
    } else {
        /* Both cycle directions blocked — use greedy */
        return getAutoDirection(
            (int(*)[GRID_W])safetyGrid,
            snakeXArr, snakeYArr, snakeLen, foodX, foodY);
    }

    /* Safety: after moving to target, check reachable space.
       If reachable < snake length, it's getting tight — prefer
       the direction that leaves more room. */
    int bestDir = dirFromTo(sx, sy, targetX, targetY);
    int bestReach = -1;

    if (!fwdBlocked) {
        int reach = countReachableOn(safetyGrid, fwdX, fwdY, snakeXArr, snakeYArr, snakeLen);
        if (reach > bestReach) {
            bestReach = reach;
            bestDir = dirFromTo(sx, sy, fwdX, fwdY);
        }
    }
    if (!backBlocked) {
        int reach = countReachableOn(safetyGrid, backX, backY, snakeXArr, snakeYArr, snakeLen);
        if (reach > bestReach) {
            bestReach = reach;
            bestDir = dirFromTo(sx, sy, backX, backY);
        }
    }

    /* If reachable space is critically low, try greedy */
    if (bestReach < snakeLen) {
        /* Tight space — use greedy which considers safety explicitly */
        int greedyDir = getAutoDirection(
            (int(*)[GRID_W])safetyGrid,
            snakeXArr, snakeYArr, snakeLen, foodX, foodY);

        /* Only use greedy if it doesn't go backward (no 180° turns) */
        int opp = oppositeDir(bestDir);
        if (greedyDir != opp) {
            return greedyDir;
        }
    }

    return bestDir;
}
