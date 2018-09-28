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
} Node, *Tree;

//转化广义表为二叉树
Tree ToTree(const char *str) {
    Tree STACK[MaxSize], p, T = NULL;
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
            p = (Tree)malloc(sizeof(Node));
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
void Expand(Tree tree) {
    if (tree == NULL)
        return;
    printf("%c", tree->data);
    int flag;
    if (tree->lChild != NULL) {
        putchar('(');
        Expand(tree->lChild);
        flag = 1;
    }
    if (tree->rChild != NULL) {
        putchar(',');
        Expand(tree->rChild);
    }
    if (flag)
        putchar(')');
}
//获取叶结点的数目
int GetLeafNum(Tree tree) {
    if (tree == NULL)
        return 0;
    if (tree->lChild == NULL && tree->rChild == NULL)
        return 1;

    return GetLeafNum(tree->lChild) + GetLeafNum(tree->rChild);
}
int max(const int a, const int b) {
    if (a >= b)
        return a;
    return b;
}
//求二叉树的深度
int GetDepth(Tree tree) {
    if (tree == NULL)
        return 0;
    return max(GetDepth(tree->lChild), GetDepth(tree->rChild)) + 1;
}

int main(int argc, char const *argv[]) {
    Tree t = ToTree("A(B(C,D(E(F,G),H(I))))@");
    Expand(t);
    int c = GetLeafNum(t);
    printf("\nLeaf Num: %d\n", c);
    c = GetDepth(t);
    printf("Depth: %d\n", c);
    return 0;
}
