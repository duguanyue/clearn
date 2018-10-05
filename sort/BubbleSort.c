#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 7
int arr[M];
void PrintArr(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d, ", arr[i]);
    }
    putchar('\n');
}
//普通版
void BubbleSort1(int arr[], int len) {
    int c;
    for (int i = 0; i < M; i++) {
        for (int j = 1; j < M - i; j++) {
            if (arr[j - 1] > arr[j]) {
                c = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = c;
            }
        }
    }
}
//优化版
void BubbleSort(int arr[], int len) {
    int i, n = len, flag = 1, temp;
    while (n > 0 && flag == 1) {
        flag = 0;
        for (i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                flag = 1;
            }
        }
        n--;
    }
}
int main(int argc, char const *argv[]) {
    srand(time(NULL));
    int i, t = 5;
    while (t--) {
        for (i = 0; i < M; i++) {
            arr[i] = rand() % 100;
            printf("%d, ", arr[i]);
        }
        puts("\n冒泡排序 ---------------------");
        BubbleSort1(arr, M);
        PrintArr(arr, M);
        puts("优化版冒泡排序 ---------------------");
        BubbleSort(arr, M);
        PrintArr(arr, M);
        putchar('\n');
    }
    return 0;
}