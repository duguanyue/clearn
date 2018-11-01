/**
1 2 1
1 3 1
1 4 1
2 1 1
2 4 1
3 1 1
3 4 1
3 5 1
4 1 1
4 2 1
4 3 1
4 5 1
5 3 1
5 4 1
6 7 1
6 9 1
7 6 1
7 8 1
8 7 1
8 9 1
9 6 1
9 8 1
 * operations of a graph.
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct edge {
    int adjvex;        //该边的终点位置
    int weight;        //权值
    struct edge *next; //指向下一条边结点
} ELink;
typedef struct vex {
    char data[5]; //顶点数据信息
    ELink *link;  //指向第一条边结点
} VLink;
//点个数
#define n 9
//边个数
#define e 22
VLink G[n];
int visited[n];
void visit(v) {
    VLink p = G[v];
    printf("%s, ", p.data);
}
void ListGraph(int len) {
    const char *s;
    int k, c;
    VLink vp;
    ELink *q;
    for (k = 0; k < len; k++) {
        vp = G[k];
        s = vp.data;
        printf("%d : %s --> ", k, s);
        q = vp.link;
        while (q != NULL) {
            c = q->adjvex;
            printf("%d, ", c);
            q = q->next;
        }
        putchar('\n');
    }
}

void DFS(const int v) {
    visit(v);
    visited[v] = 1;
    ELink *p = G[v].link;
    int w;
    if (p != NULL) {
        w = p->adjvex;
        if (visited[w] == 0) {
            DFS(w);
        }
        p = p->next;
    }
}

void TravalDFS(const int len) {
    int i;
    for (i = 0; i < n; i++)
        visited[i] = 0;

    for (i = 0; i < n; i++) {
        DFS(i);
    }
}

int main(int argc, char const *argv[]) {
    freopen("/Users/xxx/Documents/data.txt", "r", stdin);
    int k, vi, vj, weight;
    ELink *p, *q;
    for (k = 0; k < e; k++) {
        scanf("%d %d %d", &vi, &vj, &weight);
        p = (ELink *)malloc(sizeof(ELink));
        p->adjvex = vj - 1;
        p->weight = weight;
        p->next = NULL;
        if (G[vi - 1].link == NULL) {
            G[vi - 1].link = p;
        } else {
            q = G[vi - 1].link;
            while (q->next != NULL)
                q = q->next;
            q->next = p;
        }
        getchar(); //换行
    }
    //输出接表数组结构
    ListGraph(n);

    // BFS
    TravalDFS(n);

    return 0;
}