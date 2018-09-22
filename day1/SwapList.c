#include <stdio.h>
#define N 4
int main(int argc, char const *argv[]) {
    int arr[N];
    for (int i = 1; i <= N; i++) {
        *(arr + i - 1) = i;
    }
    int a = 0, b = N - 1, c;
    while (a < b) {
        c = arr[a];
        arr[a] = arr[b];
        arr[b] = c;
        ++a;
        --b;
    }
    for (int i = 0; i < N; i++) {
        printf("%-3d", *(arr + i));
    }
    return 0;
}
