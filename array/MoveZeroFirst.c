//将数组中所有的0 移动到数组的一端
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 8
int arr[N];
void test1() {
    //移动
    int i = 0, j = N - 1, temp;
    while (i < j) {
        while (i < j && arr[i] == 0)
            i++;
        while (i < j && arr[j] != 0)
            j--;
        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    for (i = 0; i < N; i++) {
        printf("%d, ", arr[i]);
    }
}
void test2() {
    int i, k = -1;
    for (i = 0; i < N; i++) {
        if (arr[i] != 0) {
            arr[++k] = arr[i];
            if (k != i) {
                arr[i] = 0;
            }
        }
    }
    for (i = 0; i < N; i++) {
        printf("%d, ", arr[i]);
    }
}
int main(int argc, char const *argv[]) {
    srand(time(NULL));
    //生成数组
    for (int i = 0; i < N; i++) {
        if (i % 3 == 0)
            arr[i] = 0;
        else
            arr[i] = rand() % 20;
        printf("%d, ", arr[i]);
    }
    puts("\n--------------------");
    //移动左端
    test1();
    puts("\n--------------------");
    //移动右端
    test2();
    return 0;
}
