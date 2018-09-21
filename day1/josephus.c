#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node {
    int data;
    struct node *next;
} Node, *List;
int main(int argc, char const *argv[]) {
    int n = 8, m = 4, k = 3;
    // n个人 从k报数 数到m的人出列 直到全部出列
    List p, r, list = NULL;
    int i;
    for (i = 1; i <= n; i++) {
        p = (List)malloc(sizeof(Node));
        p->data = i;
        if (list == NULL)
            list = p;
        else
            r->next = p;
        r = p;
    }
    p->next = list;
    // finish
    p = list;
    for (i = 1; i < k; i++) {
        r = p;
        p = p->next;
    }
    while (p->next != p) {
        for (i = 1; i < m; i++) {
            r = p;
            p = p->next;
        }
        //此时p指向m位，r指向m-1位，删除m节点
        r->next = p->next;
        printf("%-4d", p->data);
        free(p);
        p = r->next;
    }
    printf("\n最后被删除的节点是%d\n", p->data);

    return 0;
}
