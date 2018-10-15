/*
 *全排列算法递归实现
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Swap(char *a, char *b);
void Permutate(char arr[], char m, char n);
void PrintArr(char arr[], int len);
int main(int argc, char const *argv[]) {
    char arr[] = "ABC";
    Permutate(arr, 0, strlen(arr));

    return 0;
}
void PrintArr(char arr[], int len) {
    for (int i = 0; i < len; ++i) {
        printf("%c", arr[i]);
    }
}
void Permutate(char arr[], char m, char n) {
    if (m == n - 1) {
        PrintArr(arr, n);
        putchar('\n');
        return;
    }
    for (char i = m; i < n; ++i) {
        Swap(arr + m, arr + i);
        Permutate(arr, m + 1, n);
        Swap(arr + m, arr + i);
    }
}
void Swap(char *a, char *b) {
    char c = *a;
    *a = *b;
    *b = c;
}