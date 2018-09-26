//将数组中的元素循环右移K位
#include <stdio.h>
#define N 12
int arr[N];
int main(int argc, char const *argv[]) {
    //右移K位
    int k = 5;
    int i, j;
    for (i = 0; i < N; i++) {
        *(arr + i) = i * i;
        printf("%d, ", *(arr + i));
    }
    putchar('\n');
    int count = 1, temp;
    i = 0, j = 0;
    while (count < N) {
        j = (j + k) % N;
        if (j != i) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        } else {
            ++i;
            ++j;
        }
        count++;
    }

    puts("\n-----result-----\n");
    for (i = 0; i < N; i++) {
        printf("%d, ", *(arr + i));
    }
    return 0;
}
