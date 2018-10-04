#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 11
//顺序查找
int NormalSearch(int *arr, int len, int key) {
    for (int i = 0; i < len; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}
//二分查找
int BinarySearch(int *arr, int len, int key) {
    int left = 0, right = len - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
//递归二分查找
int ReBinarySearch(int *arr, int left, int right, int key) {
    if (left > right)
        return -1;
    int mid = (left + right) / 2;
    if (arr[mid] == key)
        return mid;
    if (arr[mid] < key)
        return ReBinarySearch(arr, mid + 1, right, key);
    return ReBinarySearch(arr, left, mid - 1, key);
}
int main(int argc, char const *argv[]) {
    int arr[n] = {2, 5, 8, 11, 15, 16, 22, 24, 27, 35, 50};
    srand(time(NULL));

    int i, j, k;
    for (i = 0; i < 10; i++) {
        j = rand() % 20;
        k = NormalSearch(arr, n, j);
        if (k != -1)
            printf("数字%d位置在%d\n", j, k + 1);
    }
    puts("----------------");
    for (i = 0; i < 10; i++) {
        j = rand() % 20;
        k = BinarySearch(arr, n, j);
        if (k != -1)
            printf("数字%d位置在%d\n", j, k + 1);
    }
    puts("----------------");
    for (i = 0; i < 10; i++) {
        j = rand() % 20;
        k = ReBinarySearch(arr, 0, n - 1, j);
        if (k != -1)
            printf("数字%d位置在%d\n", j, k + 1);
    }

    return 0;
}
