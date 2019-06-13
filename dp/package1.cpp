/**
假设1,2,3,4,5号物品
它们的重量分别是2,2,6,5,4，用w(i)表示
它们的价值分别是6,3,5,4,6用v(i)表示
------------
data.txt

10 5
2 6
2 3
6 5
5 4
4 6
------------
 */
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int f[200][200];
int main(int argc, char const *argv[])
{
    freopen("/Users/hehongbo/Downloads/data.txt", "r", stdin);
    int N, maxV;
    scanf("%d %d", &maxV, &N);
    int w[N + 1], v[N + 1];
    w[0] = 0;
    v[0] = 0;
    for (int i = 1; i <= N; i++)
        scanf("%d %d", w + i, v + i);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= maxV; j++)
        {
            if (j < w[i])
                f[i][j] = f[i - 1][j];
            else
                f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]] + v[i]);
        }
    }

    int *p = f[N];
    int max = 0, e = maxV;
    while (max <= 0)
    {
        max = *(p + e);
        e--;
    }

    cout << "-----最大值:" << max << "-----" << endl;

    int n = N, t = maxV;
    while (n)
    {
        if (f[n][t] == f[n - 1][t - w[n]] + v[n])
        {
            printf("第%d件价格[%d]体积[%d]\n", n, w[n], v[n]);
            t -= w[n];
        }
        n--;
    }

    return 0;
}