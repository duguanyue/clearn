/*
 *依次输入带权有向图:
 *n个顶点(假设以序号i表示第i个顶点)
 *e个表示边的顶点对偶
 *---数据:data.txt  顶点 终点 权值(该代码中权值未使用)
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
 *---
 *写一算法,建立其邻接表结构
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct edge {
    int adjvex;        //该边的终止顶点位置
    int weight;        //权值
    struct edge *next; //指向下一个边结点

} ELink;
typedef struct ver {
    char vertex[3]; //顶点数据信息
    ELink *link;    //指向第一条边对应的边结点
} VLink;

#define n 9
#define e 22
VLink G[n];
int visited[n];
void Visit(v) {
    VLink p = G[v];
    printf("%s, ", p.vertex);
}
//删除图中数据信息为c的结点(假设满足条件的结点数目不超过1个)
void Delete(const char *c) {
    int len = n;
    int i, k = -1;
    ELink *p, *q, *r;
    for (int i = 0; i < len && strcmp(G[i].vertex, c) != 1; i++) {
        k = i;
    }

    if (k == -1) {
        return;
    }

    //找到满足条件的结点
    p = G[k].link;
    //删除一个顶点,即将后续顶点全部左移
    for (i = k + 1; i < len; i++) {
        strcpy(G[k - 1].vertex, G[k].vertex);
        G[k - 1].link = G[k].link;
    }
    //数组长度减少1
    len--;
    while (p) {
        r = p;
        p = p->next;
        free(p);
    }

    for (i = 0; i < len; i++) {
        p = G[i].link;
        while (p != NULL) {
            if (p->adjvex == k) {
                // p所指的边结点的adjvex域为k
                if (G[i].link == p) {
                    G[i].link = p->next;
                } else {
                    q->next = p->next;
                }

                r = p;
                p = p->next;
                free(r);
            } else {
                if (p->adjvex > k) {
                    p->adjvex--;
                }
                q = p;
                p = p->next;
            }
        }
    }
}
//深度优先遍历 递归
void DFS(int v) {
    Visit(v);
    visited[v] = 1;
    // int w = FirstAdj(v);
    ELink *p;
    p = G[v].link;
    int w;
    if (p == NULL)
        w = -1;
    else
        w = p->adjvex;
    p = p->next;
    while (w != -1) {
        if (visited[w] == 0) {
            DFS(w);
        }
        if (p != NULL) {
            w = p->adjvex;
            p = p->next;
        } else {
            w = -1;
        }
    }
}
void TravelDFS() {
    puts("------DFS------");
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            DFS(i);
        }
    }
}
int main(int argc, char const *argv[]) {
    // 5个顶点,8条边
    int k, vi, vj, weight;
    ELink *p, *q;
    //建立n个顶点结点
    for (k = 0; k < n; k++) {
        sprintf(G[k].vertex, "v%d", k + 1);
        G[k].link = NULL;
    }
    //读取e条边的数据
    freopen("/Users/hehongbo/Documents/data.txt", "r", stdin);
    for (k = 0; k < e; k++) {
        scanf("%d %d %d", &vi, &vj, &weight);
        getchar();
        p = (ELink *)malloc(sizeof(ELink));
        p->adjvex = vj - 1;
        p->weight = weight;
        p->next = NULL;
        if (!G[vi - 1].link) {
            //如果第vi个链表只有头结点
            G[vi - 1].link = p;
        } else {
            q = G[vi - 1].link;
            while (q->next != NULL) {
                q = q->next;
            }
            q->next = p;
        }
    }
    //输出邻接表结构
    const char *s;
    int c;
    for (k = 0; k < n; k++) {
        VLink vp = G[k];
        s = vp.vertex;
        printf("%s --> ", s);
        p = vp.link;
        while (p != NULL) {
            c = p->adjvex;
            printf("%d, ", c);
            p = p->next;
        }
        putchar('\n');
    }

    // 深度优先搜索 递归
    TravelDFS();

    return 0;
}
