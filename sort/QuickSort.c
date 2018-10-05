#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 10
int K[M];
void Swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}
void QuickSort(int arr[], int s, int t) {
    if (s >= t)
        return;
    int i = s, k = t + 1;
    while (1) {
        do
            ++i;
        while (arr[i] < arr[s] && i <= k);
        do
            --k;
        while (arr[k] > arr[s] && i <= k);
        if (i < k)
            Swap(arr + i, arr + k);
        else
            break;
    }
    Swap(arr + s, arr + k);
    QuickSort(arr, s, k - 1);
    QuickSort(arr, k + 1, t);
}
void QuickSort2(int arr[], int s, int t) {
    if (s >= t)
        return;
    int i = s, k = t + 1;
    while (1) {
        do
            i++;
        while (arr[i] < arr[s] && i <= k);
        do
            k--;
        while (arr[k] > arr[s] && i <= k);
        if (i < k)
            Swap(arr + i, arr + k);
        else
            break;
    }
    Swap(arr + s, arr + k);
    QuickSort(arr, s, k - 1);
    QuickSort(arr, k + 1, t);
}
int main(int argc, char const *argv[]) {
    srand(time(NULL));
    int i, t = 6;
    while (t--) {
        for (i = 0; i < M; i++) {
            K[i] = rand() % 100;
            printf("%d, ", K[i]);
        }
        puts("\n快速排序 --------------------");
        QuickSort(K, 0, M - 1);

        for (i = 0; i < M; i++) {
            printf("%d, ", K[i]);
        }
        puts("\n快速排序2 --------------------");
        QuickSort2(K, 0, M - 1);

        for (i = 0; i < M; i++) {
            printf("%d, ", K[i]);
        }
        printf("\n\n");
    }
}