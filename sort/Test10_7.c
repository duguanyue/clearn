#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MaxSize 100
void Swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}
void Adjust(int arr[], int i, int len) {
    int j, c = arr[i];
    while ((j = i * 2 + 1, j) < len) {
        if (j + 1 < len && arr[j + 1] > arr[j])
            j++;
        if (arr[j] > c)
            Swap(arr + j, arr + i);
        else
            break;
        i = j;
    }
    arr[i] = c;
}
void Insert(int arr[], int *len, int item) {
    int i;
    int n = *len;
    (*len)++;
    while (n) {
        i = (n - 1) / 2;
        if (arr[i] >= item)
            break;
        arr[n] = arr[i];
        n = i;
    }
    arr[n] = item;
}
int main(int argc, char const *argv[]) {
    srand(time(NULL));
    int M = 7;
    int arr[MaxSize], i, t = 5;
    while (t--) {
        for (i = 0; i < M; i++) {
            arr[i] = rand() % 100;
            printf("%d, ", arr[i]);
        }

        for (i = M / 2; i >= 0; i--)
            Adjust(arr, i, M);

        puts("\n调整后---------------------");
        for (i = 0; i < M; i++)
            printf("%d, ", arr[i]);

        i = rand() % 100;
        printf("\n插入随机数%d--------------------\n", i);
        Insert(arr, &M, i);
        for (i = 0; i < M; i++)
            printf("%d, ", arr[i]);

        puts("\n\n");
    }
    return 0;
}