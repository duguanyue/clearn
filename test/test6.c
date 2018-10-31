#include <stdio.h>
#include <stdlib.h>
#define M 100
typedef struct tree {
    char data;
    struct tree *lChild, *rChild;
} Node, *Tree;
Tree STACK[M];
Tree toTree(const char *str) {
    Tree t = NULL, p = NULL;
    int flag, i = 0, top = -1;
    char ch;
    while (1) {
        ch = *(str + i++);
        switch (ch) {
        case '@':
            return t;
        case '(':
            STACK[++top] = p;
            flag = 1;
            break;
        case ')':
            --top;
            break;
        case ',':
            flag = 2;
            break;
        default:
            p = (Tree)malloc(sizeof(Node));
            p->data = ch;
            p->lChild = NULL;
            p->rChild = NULL;
            if (t == NULL)
                t = p;
            else if (flag == 1)
                STACK[top]->lChild = p;
            else
                STACK[top]->rChild = p;
            break;
        }
    }
    return NULL;
}

void LDR(Tree t) {
    if (t) {
        LDR(t->lChild);
        printf("%c ", t->data);
        LDR(t->rChild);
    }
}

int main(int argc, char const *argv[]) {
    const char *str = "A(B(C,D(E(F,G),H(I))))@";
    Tree t = toTree(str);
    LDR(t);
    return 0;
}