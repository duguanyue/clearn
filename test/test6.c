#include <stdio.h>
#include <stdlib.h>
#define M 100
typedef struct tree {
    char data;
    struct tree *lChild, *rChild;
} Node, *Tree;
Tree STACK[M];
void Visit(Tree t) {
    // print
    if (t == NULL)
        printf("NULL");
    else
        printf("%c, ", t->data);
}
Tree ToTree(const char *str) {
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

/**
 * 中序遍历
 */
void LDR(Tree t) {
    if (t) {
        LDR(t->lChild);
        Visit(t);
        LDR(t->rChild);
    }
}
/**
 * 非递归中序遍历
 */
void NoReLDR(Tree t) {
    Tree p = t;
    int top = -1;
    while (p || top != -1) {
        while (p) {
            STACK[++top] = p;
            p = p->lChild;
        }
        p = STACK[top--];
        Visit(p);
        p = p->rChild;
    }
}
/**
 * 前序遍历
 */
void DLR(Tree t) {
    if (t) {
        Visit(t);
        DLR(t->lChild);
        DLR(t->rChild);
    }
}
/**
 * 非递归前序遍历
 */
void NoReDLR(Tree t) {
    Tree p = t;
    int top = -1;
    while (p || top != -1) {
        while (p) {
            Visit(p);
            STACK[++top] = p;
            p = p->lChild;
        }
        p = STACK[top--];
        p = p->rChild;
    }
}
/**
 * 后序遍历
 */
void LRD(Tree t) {
    if (t) {
        LRD(t->lChild);
        LRD(t->rChild);
        Visit(t);
    }
}

void NoReLRD(Tree t) {
    int top = -1, flag, FLAG[M];
    Tree p = t;
    while (p || top != -1) {
        while (p) {
            STACK[++top] = p;
            FLAG[top] = 0;
            p = p->lChild;
        }
        p = STACK[top];
        flag = FLAG[top--];
        if (flag == 0) {
            STACK[++top] = p;
            FLAG[top] = 1;
            p = p->rChild;
        } else {
            Visit(p);
            p = NULL;
        }
    }
}

int main(int argc, char const *argv[]) {
    const char *str = "A(B(D(G,H),E),C(F(I)))@";
    Tree t = ToTree(str);
    puts("\n前序遍历");
    DLR(t);
    puts("\n前序遍历非递归");
    NoReDLR(t);
    puts("\n中序遍历");
    LDR(t);
    puts("\n中序遍历非递归");
    NoReLDR(t);
    puts("\n后序遍历");
    LRD(t);
    puts("\n后序遍历非递归");
    NoReLRD(t);
    return 0;
}