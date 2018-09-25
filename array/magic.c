#include <stdio.h>
#include <stdlib.h>
#define N 5
/**
 * N阶魔方
 * 每一行，每一列，对角线 相加之和相等
 */
int arr[N][N];
int main(int argc, char const *argv[]) {
    int m = 0, n = N / 2;
    for (int c = 1; c <= N * N; c++) {
        if ((m < 0 && n < 0) || arr[m][n] != 0) {
            m += 2;
            n++;
        }
        arr[m--][n--] = c;
        if (m < 0 && n >= 0) {
            m = N - 1;
        }
        if (m >= 0 && n < 0) {
            n = N - 1;
        }
    }
    for (m = 0; m < N; m++) {
        for (n = 0; n < N; n++) {
            printf("%-4d", arr[m][n]);
        }
        putchar('\n');
    }
    return 0;
}
