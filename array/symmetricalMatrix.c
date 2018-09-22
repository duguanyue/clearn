#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * 4阶矩阵 关于主对角线对称
 * 1  2  3  4
 * 2  4  6  8
 * 3  6  12 16
 * 4  8  16 32
 */
#define N 7
int Index(int i, int j) {
    if (i < j)
        return Index(j, i);
    return i * (i - 1) / 2 + j - 1;
}
int main(int argc, char const *argv[]) {
    int len = N * (N + 1) / 2;
    int arr[len];
    memset(arr, 0, sizeof(arr));
    //根据算法存储压缩矩阵
    int i, j, k = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j <= i; j++) {
            arr[k++] = (i + 1) * pow(2, j);
        }
    }
    for (i = 0; i < k; i++) {
        printf("%d  ", *(arr + i));
    }
    puts("\n-----------------------------");
    //根据压缩矩阵显示原始矩阵
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            printf("%-4d", arr[Index(i, j)]);
        }
        putchar('\n');
    }

    return 0;
}
