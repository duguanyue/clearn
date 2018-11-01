//根据输入生成一个带权图的矩阵
#include <stdio.h>
#define MaxNum 8
int arr[MaxNum][MaxNum];
void AdjMatrix(int n, int e) {
    int i, j, k, weight;
    for (i = 0; i < MaxNum; i++)
        for (j = 0; j < MaxNum; j++)
            arr[i][j] = 0;

    freopen("/Users/xxx/Documents/data.txt", "r", stdin);
    for (k = 0; k < e; k++) {
        scanf("i=%d,j=%d,weight=%d", &i, &j, &weight);
        arr[i][j] = arr[j][i] = weight;
        getchar();
    }
}
int main(int argc, char const *argv[]) {
    AdjMatrix(5, 7);

    int i, j;
    for (i = 0; i < MaxNum; i++) {
        for (j = 0; j < MaxNum; j++)
            printf("%-3d", arr[i][j]);
        putchar('\n');
    }
    return 0;
}
