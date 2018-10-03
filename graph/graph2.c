/*
 *依次输入带权有向图:
 *n个顶点(假设以序号i表示第i个顶点)
 *e个表示边的顶点对偶
 *---
 *写一算法,建立其邻接表结构
 */
#include <stdio.h>
typedef struct edge {
    int adjvex;        //该边的终止顶点位置
    int weight;        //权值
    struct edge *next; //指向下一个边结点

} ELink;
typedef struct ver {
    char vertex; //顶点数据信息
    ELink *link; //指向第一条边对应的边结点
} VLink;
//删除图中数据信息为c的结点(假设满足条件的结点数目不超过1个)
void Delete(VLink G[], int n, char c) {
    int i, k = -1;
    ELink *p, *q, *r;
    for (int i = 0; i < n; i++) {
        if (G[i].vertex == c) {
            k = i;
            break;
        }
    }
    if (k != -1) {
        //找到满足条件的结点
        p = G[k].link;
        //删除一个顶点,即将后续顶点全部左移
        for (i = k + 1; i < n; i++) {
            G[k - 1].vertex = G[k].vertex;
            G[k - 1].link = G[k].link;
        }
        //数组长度减少1
        n--;
        while (p) {
            r = p;
            p = p->next;
            free(p);
        }

        for (i = 0; i < n; i++) {
            p = G[i].link;
            while (p) {
                if (p->adjvex == k) {
                    // p所指的边结点的adjvex域为k
                    if (G[i].link == p)
                        G[i].link = p->next;
                    else
                        q->next = p->next;

                    r = p;
                    p = p->next;
                    free(r);
                } else {
                    if (p->adjvex > k)
                        p->adjvex--;
                    q = p;
                    p = p->next;
                }
            }
        }
    }
}
int main(int argc, char const *argv[]) {
    // 5个顶点,8条边
    int n = 5, e = 8;
    int k, vi, vj, weight;
    ELink *p, *q;
    VLink G[n];
    //建立n个顶点结点
    for (k = 0; k < n; k++) {
        G[k].vertex = k;
        G[k].link = NULL;
    }
    //读取e条边的数据
    freopen("/Users/hehongbo/Documents/data.txt", "r", stdin);
    for (k = 0; k < e; k++) {
        scanf("%d %d %d", &vi, &vj, &weight);
        p = (ELink *)malloc(sizeof(ELink));
        p->adjvex = vj - 1;
        p->weight = weight;
        p->next = NULL;
        if (!G[vi - 1].link) {
            //如果第vi个链表只有头结点
            G[vi - 1].link = p;
        } else {
            q = G[vi - 1].link;
            while (q->next)
                q = q->next;
            q->next = p;
        }
    }

    //
    return 0;
}
