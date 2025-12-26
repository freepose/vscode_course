

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 假设数据范围为-100000~100000
#define OFFSET 100000
#define MAXN 200005

int main()
{
    int n = 0, has_duplicate = 0;
    scanf("%d", &n);
    if (n == 1) {
        printf("NO\n");
        return 0;
    }
    static char vis[MAXN] = {0};
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        int idx = x + OFFSET;
        if (vis[idx]) {
            has_duplicate = 1;
            break;
        }
        vis[idx] = 1;
    }
    printf("%s\n", has_duplicate ? "YES" : "NO");
    return 0;
}