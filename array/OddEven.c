//将随机数组中的奇数与偶数分开,左边为奇数,右边为偶数,要求O(n)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 11
int arr[N];
void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(int argc, char const *argv[]) {
    srand(time(NULL));
    //生成数组
    int i, j;
    for (i = 0; i < N; i++) {
        arr[i] = rand() % 100;
        printf("%-4d", arr[i]);
    }
    //分离
    i = 0, j = N - 1;
    while (i < j) {
        while (i < j && arr[i] % 2 != 0)
            i++;
        while (i < j && arr[j] % 2 == 0)
            j--;
        if (i < j)
            Swap(&arr[i], &arr[j]);
    }

    puts("\n----------");
    for (i = 0; i < N; i++) {
        printf("%-4d", arr[i]);
    }

    return 0;
}
