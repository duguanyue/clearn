#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 5
int Index(int i, int j) { return i * (i - 1) / 2 + j - 1; }
int arr[N][N];
int main(int argc, char const *argv[]) {
    srand(time(NULL));
    int i, j;
    //创建下三角矩阵
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (j <= i) {
                arr[i][j] = rand() % 20 + 1;
            } else {
                arr[i][j] = -5;
            }
            printf("%-5d", arr[i][j]);
        }
        putchar('\n');
    }
    puts("---------------------");
    //压缩
    int len = N * (N + 1) / 2 + 1;
    int c[len];
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            if (i >= j) {
                c[Index(i, j)] = arr[i - 1][j - 1];
            }
        }
    }
    c[len - 1] = -5;

    for (i = 0; i < len; i++) {
        printf("%-4d", c[i]);
    }
    return 0;
}
