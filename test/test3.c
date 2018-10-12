/*
 *排序
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 10

typedef void (*Func)(int *, int);
int arr[M];
void Swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}
void Random(int *arr, int len) {
    puts("\n----------随机数组----------");
    for (int i = 0; i < len; i++) {
        arr[i] = rand() % 100;
        printf("%2d, ", arr[i]);
    }
    putchar('\n');
}
void PrintArr(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%2d, ", arr[i]);
    }
}
void Sort(int *arr, int len, Func func) {
    Random(arr, len);
    func(arr, len);
    PrintArr(arr, len);
}
void SelectSort(int *arr, int len) {
    puts("----------选择排序----------");
    int i, j;
    for (int i = 0; i < len - 1; i++) {
        for (j = i + 1; j < len; j++) {
            if (arr[i] > arr[j]) {
                Swap(arr + i, arr + j);
            }
        }
    }
}

void BubbleSort(int *arr, int len) {
    puts("----------冒泡排序-----------");
    int i, n = len, flag = 1;
    while (len > 0 && flag == 1) {
        flag = 0;
        for (i = 1; i < n; i++) {
            if (arr[i - 1] > arr[i]) {
                Swap(arr + i - 1, arr + i);
                flag = 1;
            }
        }
        n--;
    }
}
void InsertSort(int *arr, int len) {
    puts("----------插入排序-----------");
    int i, j, c;
    for (i = 1; i < len; i++) {
        c = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > c; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = c;
    }
}
void QSort(int *arr, int left, int right) {
    if (left < right) {
        int s = left, e = right + 1, pivot = arr[left];
        while (s < e) {
            do {
                ++s;
            } while (s <= e && arr[s] < pivot);
            do {
                --e;
            } while (s <= e && arr[e] > pivot);
            if (s < e) {
                Swap(arr + s, arr + e);
            }
        }
        Swap(arr + left, arr + e);
        QSort(arr, left, e - 1);
        QSort(arr, e + 1, right);
    }
}
void MergeArr(int *arr, int left, int mid, int right, int *tmpArr) {
    int s = left, k = mid + 1, n = 0;
    while (s <= mid && k <= right) {
        if (arr[s] <= arr[k]) {
            tmpArr[n++] = arr[s++];
        } else {
            tmpArr[n++] = arr[k++];
        }
    }
    while (s <= mid) {
        tmpArr[n++] = arr[s++];
    }
    while (k <= right) {
        tmpArr[n++] = arr[k++];
    }
    while (n > 0) {
        arr[right--] = tmpArr[--n];
    }
}
void MSort(int *arr, int left, int right, int *tmpArr) {
    if (left < right) {
        int mid = (left + right) / 2;
        MSort(arr, left, mid, tmpArr);
        MSort(arr, mid + 1, right, tmpArr);
        MergeArr(arr, left, mid, right, tmpArr);
    }
}
void MergeSort(int *arr, int len) {
    int *tmpArr = (int *)malloc(sizeof(int) * len);
    MSort(arr, 0, len - 1, tmpArr);
}
void QuickSort(int *arr, int len) {
    puts("----------快速排序-----------");
    QSort(arr, 0, len - 1);
}

int main(int argc, char const *argv[]) {
    srand(time(NULL));
    Sort(arr, M, SelectSort);
    Sort(arr, M, BubbleSort);
    Sort(arr, M, InsertSort);
    Sort(arr, M, QuickSort);
    Sort(arr, M, MergeSort);

    return 0;
}