#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 11

void PrintArr(int arr[], int len) {
    for (int i = 0; i < M; i++) {
        printf("%d, ", arr[i]);
    }
    putchar('\n');
}
void InsertSort(int arr[], int len) {
    int i, j, c;
    for (i = 1; i < len; i++) {
        c = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > c) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = c;
    }
}
void InsertSort2(int arr[], int len) {
    int c;
    for (int i = 1; i < len; i++) {
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
            c = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = c;
        }
    }
}
void BinaryInsertSort(int arr[], int len) {
    int i, j, low, high, mid;
    int c;
    for (i = 1; i < len; i++) {
        c = arr[i];
        low = 0;
        high = i - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (c < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        for (j = i - 1; j >= low; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = c;
    }
}
int main(int argc, char const *argv[]) {
    int arr[M];
    srand(time(NULL));
    int i;
    for (i = 0; i < M; i++) {
        arr[i] = rand() % 100;
        printf("%d, ", arr[i]);
    }

    puts("直接插入排序 --------------------");
    InsertSort(arr, M);
    PrintArr(arr, M);
    puts("直接插入排序2 --------------------");
    InsertSort2(arr, M);
    PrintArr(arr, M);
    puts("二分直接插入排序2 --------------------");
    BinaryInsertSort(arr, M);
    PrintArr(arr, M);

    return 0;
}
