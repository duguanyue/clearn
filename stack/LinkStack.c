//堆栈的链表表示法 又称 链栈
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} Node, *Stack;
Stack top;
void Init() { top = NULL; }
int IsEmpty() { return top == NULL; }
int Pop(int *item) {
    if (IsEmpty()) {
        return 0;
    }
    Stack p = top;
    *item = top->data;
    top = top->next;
    free(p);
    return 1;
}
int Push(int item) {
    Stack p = (Stack)malloc(sizeof(Node));
    p->data = item;
    p->next = top;
    top = p;
    return 1;
}
int main(int argc, char const *argv[]) {
    Init();
    //设值
    int i;
    for (i = 0; i < 10; i++) {
        Push(i);
    }

    //取值
    while (!IsEmpty()) {
        Pop(&i);
        printf("%-3d", i);
    }

    return 0;
}
