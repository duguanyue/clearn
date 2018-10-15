#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//使用大根堆
#define M 7
int arr[M];
void Swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}
void Adjust(int arr[], int i, int n) {
    int j, c = arr[i];
    while ((j = 2 * i + 1) < n) {
        if (j + 1 < n && arr[j] < arr[j + 1])
            j++;
        if (c < arr[j])
            Swap(arr + i, arr + j);
        else
            break;
        i = j;
    }
    arr[i] = c;
}
int main(int argc, char const *argv[]) {
    srand(time(NULL));
    int i, t = 6;
    while (t--) {
        for (i = 0; i < M; i++) {
            arr[i] = rand() % 100;
            printf("%d, ", arr[i]);
        }
        puts("\n堆排序(大根堆)-----------------");
        for (i = M / 2; i >= 0; i--)
            Adjust(arr, i, M);
        for (i = M - 1; i > 0; i--) {
            Swap(arr, arr + i);
            Adjust(arr, 0, i);
        }
        //输出
        for (i = 0; i < M; i++) {
            printf("%d, ", arr[i]);
        }
        printf("\n\n");
    }
    return 0;
}