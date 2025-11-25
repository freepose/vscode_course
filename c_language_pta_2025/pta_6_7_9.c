#include <stdio.h>

int main(void) 
{
    int T;
    if (scanf("%d", &T) != 1) return 0;

    int t;
    int t_dist = 0;     // 乌龟距离
    int r_dist = 0;     // 兔子距离

    int r_rest_left = 0; // 兔子还需要休息多少分钟；0 表示正在跑
    int run_cnt = 0;     // 当前这一轮已经跑了多少分钟（1~10）

    for (t = 1; t <= T; t++) {
        // 乌龟：一直跑
        t_dist += 3;

        if (r_rest_left > 0) {
            // 兔子在休息
            r_rest_left--;
            // 休息时不动
        } else {
            // 兔子在跑
            r_dist += 9;
            run_cnt++;

            if (run_cnt == 10) {
                if (r_dist > t_dist) {
                    // 跑完 10 分钟且在前，开始休息 30 分钟
                    r_rest_left = 30;
                    run_cnt = 0;     // 下次重新计跑的 10 分钟
                } else {
                    // 不在前，继续下一轮 10 分钟跑
                    run_cnt = 0;
                }
            }
        }
    }

    if (t_dist > r_dist) {
        printf("@_@ %d\n", t_dist);
    } else if (r_dist > t_dist) {
        printf("^_^ %d\n", r_dist);
    } else {
        printf("-_- %d\n", t_dist);
    }

    return 0;
}