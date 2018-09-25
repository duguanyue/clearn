#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 5
int matrix[N][N];
int main(int argc, char const *argv[]) {
    //创建一个三对角矩阵
    srand(time(NULL));
    int i, j;
    for (i = 0; i < N; i++) {
        int *p = matrix[i];
        for (j = 0; j < N; j++) {
            if (abs(i - j) > 1)
                *(p + j) = 0;
            else
                *(p + j) = rand() % 20 + 1;
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%-4d", *(*(matrix + i) + j));
        }
        putchar('\n');
    }
    puts("-------------------------");
    //压缩
    int len = 3 * N - 2;
    int c[len];
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            if (abs(i - j) <= 1) {
                c[i * 2 + j - 3] = matrix[i - 1][j - 1];
            }
        }
    }

    for (i = 0; i < len; i++) {
        printf("%-4d", *(c + i));
    }

    return 0;
}
