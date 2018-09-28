#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxSize 100
/*
广义表转化为二叉树
 */
typedef struct node {
    int data;
    struct node *lChild, *rChild;
} Node, *BTree;

//转化广义表为二叉树
BTree change(const char *str) {
    BTree STACK[MaxSize], p, T = NULL;
    char ch;
    int flag, i = 0, top = -1;
    while (1) {
        ch = *(str + i++);
        switch (ch) {
        case '@':
            return T;
        case '(':
            STACK[++top] = p;
            flag = 1;
            break;
        case ')':
            top--;
            break;
        case ',':
            flag = 2;
            break;
        default:
            p = (BTree)malloc(sizeof(Node));
            p->data = ch;
            p->lChild = NULL;
            p->rChild = NULL;
            if (T == NULL)
                T = p;
            else if (flag == 1)
                STACK[top]->lChild = p;
            else
                STACK[top]->rChild = p;
            break;
        }
    }
}

//中序输出树,输出为广义表样式
void expand(BTree tree) {
    if (tree == NULL)
        return;
    printf("%c", tree->data);
    int flag;
    if (tree->lChild != NULL) {
        putchar('(');
        expand(tree->lChild);
        flag = 1;
    }
    if (tree->rChild != NULL) {
        putchar(',');
        expand(tree->rChild);
    }
    if (flag)
        putchar(')');
}

int main(int argc, char const *argv[]) {
    BTree t = change("A(B(C,D(E(F,G),H(I))))@");
    expand(t);
    return 0;
}
