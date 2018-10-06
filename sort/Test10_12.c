#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 10
int main(int argc, char const *argv[]) {
    srand(time(NULL));
    int A[M], B[M], C[M], i, j;
    for (i = 0; i < M; i++) {
        A[i] = rand() % 100;
        printf("%d, ", A[i]);
    }

    for (i = 0; i < M; i++) {
        B[i] = 0;
        for (j = 0; j < M; j++) {
            if (A[j] < A[i])
                B[i]++;
        }
    }

    for (i = 0; i < M; i++) {
        C[B[i]] = A[i];
    }
    puts("After sort --------------------");

    for (i = 0; i < M; i++)
        printf("%d, ", C[i]);
    return 0;
}