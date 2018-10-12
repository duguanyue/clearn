/*
 *将一个链表转为逆序
 */
#include <stdio.h>
#include <stdlib.h>
#define M 10
typedef struct node {
    int data;
    struct node *next;
} Node, *List;
int main(int argc, char const *argv[]) {
    int i;
    List list, p, q, r;
    for (i = 0; i < M; i++) {
        p = (List)malloc(sizeof(Node));
        p->data = i * i;
        p->next = NULL;
        if (list == NULL) {
            list = p;
        } else {
            q->next = p;
        }
        q = p;
    }
    puts("正向:");
    p = list;
    while (p != NULL) {
        printf("%d, ", p->data);
        p = p->next;
    }
    puts("\n逆向:");
    p = list, q = NULL;
    while (p != NULL) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    while (q != NULL) {
        printf("%d, ", q->data);
        q = q->next;
    }

    return 0;
}