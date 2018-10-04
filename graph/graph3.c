/*
1 2 16
1 3 20
1 4 19
2 1 16
2 3 11
2 5 6
2 6 5
3 1 20
3 2 11
3 4 22
3 5 14
4 1 19
4 3 22
4 5 18
5 2 6
5 3 14
5 4 18
5 6 9
6 2 5
6 5 9
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct edge {
    int vertex;        //边终点
    int weight;        //权值
    struct edge *next; //下一条边
} ELink;
typedef struct ver {
    char data[3]; //点数据
    ELink *link;  //第一条边
} VLink;
#define n 6
#define e 20
VLink G[n];
int visited[n];
VLink QUEUE[n];
int front, rear;
void Visit(int v) { printf("%s, ", G[v].data); }
void DFS(int v) {
    Visit(v);
    visited[v] = 1;
    ELink *p = G[v].link;
    int w;
    while (p) {
        w = p->vertex;
        if (visited[w] == 0) {
            visited[w] = 1;
            DFS(w);
        }
        p = p->next;
    }
}
void TravelDFS(VLink G[], int len) {
    int k;
    for (k = 0; k < len; k++) {
        visited[k] = 0;
    }
    for (k = 0; k < len; k++) {
        if (visited[k] == 0) {
            DFS(k);
            putchar('/');
        }
    }
}
void BFS(int v) {
    Visit(v);
    visited[v] = 1;
    QUEUE[++rear] = G[v];
    ELink *p;
    int w;
    while (front < rear) {
        p = QUEUE[++front].link;
        while (p) {
            w = p->vertex;
            if (visited[w] == 0) {
                Visit(w);
                visited[w] = 1;
                QUEUE[++rear] = G[w];
            }
            p = p->next;
        }
    }
}
void TravelBFS(VLink G[], int len) {
    int k, j, front = -1, rear = -1;
    for (k = 0; k < len; k++) {
        visited[k] = 0;
    }
    for (k = 0; k < len; k++) {
        if (visited[k] == 0) {
            BFS(k);
            putchar('/');
        }
    }
}
int main(int argc, char const *argv[]) {
    int k, j, vi, vj, weight;
    int GE[n][n];
    for (k = 0; k < n; k++) {
        sprintf(G[k].data, "v%d", k + 1);
        G[k].link = NULL;
        for (j = 0; j < n; j++) {
            GE[k][j] = -1;
        }
    }
    freopen("/Users/hehongbo/Documents/data.txt", "r", stdin);
    ELink *p, *q;
    for (k = 0; k < e; k++) {
        scanf("%d %d %d", &vi, &vj, &weight);
        GE[vi - 1][vj - 1] = GE[vj - 1][vi - 1] = weight;
        getchar();
        p = (ELink *)malloc(sizeof(ELink));
        p->vertex = vj - 1;
        p->weight = weight;
        p->next = NULL;
        if (G[vi - 1].link == NULL) {
            G[vi - 1].link = p;
        } else {
            q = G[vi - 1].link;
            while (q->next != NULL) {
                q = q->next;
            }
            q->next = p;
        }
    }
    // list
    for (k = 0; k < n; k++) {
        printf("%d) %s ---> ", k, G[k].data);
        p = G[k].link;
        while (p) {
            printf("%d,", p->vertex);
            p = p->next;
        }
        putchar('\n');
    }

    puts("DFS  ------------------");
    TravelDFS(G, n);
    puts("\nBFS  ------------------");
    TravelBFS(G, n);
    //邻接矩阵
    puts("\n邻接矩阵 ------------------");
    int c;
    for (k = 0; k < n; k++) {
        for (j = 0; j < n; j++) {
            c = GE[k][j];
            if (c == -1)
                printf("%3c", '-');
            else
                printf("%3d", c);
        }
        putchar('\n');
    }
    return 0;
}
