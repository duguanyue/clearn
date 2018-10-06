#include <stdio.h>
#include <stdlib.h>
#define M 10
void Swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}
int main(int argc, char const *argv[]) {
    int arr[M] = {1, -2, -3, 9, 7, 5, -12, -6, -8, 2};
    int A[M + 1];
    int i = 0;
    A[0] = 0;
    while (i < M + 1) {
        A[i + 1] = arr[i];
        i++;
    }
    for (i = 0; i < M + 1; i++)
        printf("%d, ", A[i]);

    int j = M + 1, pivot = A[0];
    i = 0;
    while (1) {
        do
            ++i;
        while (A[i] < pivot && i <= j);
        do
            --j;
        while (A[j] > pivot && i <= j);
        if (i < j) {
            Swap(A + i, A + j);
        } else
            break;
    }
    Swap(A, A + j);
    puts("\nAfter Sort --------------------");
    for (i = 0; i < M + 1; i++)
        printf("%d, ", A[i]);
    return 0;
}