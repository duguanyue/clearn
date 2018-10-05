#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 5
int arr[M];
void SelectSort(int arr[], int len) {
    int c;
    for (int i = 0; i < M - 1; i++) {
        for (int j = i + 1; j < M; j++) {
            if (arr[i] > arr[j]) {
                c = arr[i];
                arr[i] = arr[j];
                arr[j] = c;
            }
        }
    }
}
void SelectSort2(int arr[], int len) {
    int d, t;
    for (int i = 0; i < len; i++) {
        d = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[d])
                d = j;
        }
        if (d != i) {
            t = arr[d];
            arr[d] = arr[i];
            arr[i] = t;
        }
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

        puts("\n选择排序 --------------------");
        SelectSort(arr, M);
        for (i = 0; i < M; i++) {
            printf("%d, ", arr[i]);
        }
        puts("\n选择排序2 --------------------");
        SelectSort2(arr, M);
        for (i = 0; i < M; i++) {
            printf("%d, ", arr[i]);
        }
        printf("\n\n");
    }
    return 0;
}