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

void Visit(Tree tree) { printf("%c, ", tree->data); }

void DLR(Tree tree) {
    if (tree != NULL) {
        Visit(tree);
        DLR(tree->lChild);
        DLR(tree->rChild);
    }
}
void LDR(Tree tree) {
    if (tree != NULL) {
        LDR(tree->lChild);
        Visit(tree);
        LDR(tree->rChild);
    }
}
void LRD(Tree tree) {
    if (tree != NULL) {
        LRD(tree->lChild);
        LRD(tree->rChild);
        Visit(tree);
    }
}
//非递归前序遍历
void NoReDLR(Tree tree) {
    Tree STACK[MaxSize], p = tree;
    int top = -1;
    while (p != NULL || top != -1) {
        while (p != NULL) {
            Visit(p);
            STACK[++top] = p;
            p = p->lChild;
        }
        p = STACK[top--];
        p = p->rChild;
    }
}
//非递归中序遍历
void NoReLDR(Tree tree) {
    Tree STACK[MaxSize], p = tree;
    int top = -1;
    while (p != NULL || top != -1) {
        while (p != NULL) {
            STACK[++top] = p;
            p = p->lChild;
        }
        p = STACK[top--];
        Visit(p);
        p = p->rChild;
    }
}
//非递归后序遍历
void NoReLRD(Tree tree) {
    Tree STACK[MaxSize], p = tree;
    int FLAG[MaxSize], flag, top = -1;
    while (p != NULL || top != -1) {
        while (p != NULL) {
            STACK[++top] = p;
            FLAG[top] = 0;
            p = p->lChild;
        }
        p = STACK[top];
        flag = FLAG[top--];
        if (flag) {
            Visit(p);
            p = NULL;
        } else {
            STACK[++top] = p;
            FLAG[top] = 1;
            p = p->rChild;
        }
    }
}

//按层次遍历
void LayerOrder(Tree tree) {
    if (tree == NULL)
        return;
    Tree QUEUE[MaxSize], p = tree;
    int front = -1, rear = 0;
    QUEUE[rear] = tree;
    while (front < rear) {
        p = QUEUE[++front];
        Visit(p);
        if (p->lChild) {
            QUEUE[++rear] = p->lChild;
        }
        if (p->rChild) {
            QUEUE[++rear] = p->rChild;
        }
    }
}

int main(int argc, char const *argv[]) {
    Tree t = ToTree("A(B(C,D(E(F,G),H(I))))@");
    Expand(t);
    int c = GetLeafNum(t);
    printf("\n叶子结点数目: %d\n", c);
    c = GetDepth(t);
    printf("深度: %d", c);
    puts("\n-------------前序遍历-------------");
    DLR(t);
    puts("\n-------------非递归前序遍历-------------");
    NoReDLR(t);
    puts("\n-------------中序遍历-------------");
    LDR(t);
    puts("\n-------------非递归中序遍历-------------");
    NoReLDR(t);
    puts("\n-------------后序遍历-------------");
    LRD(t);
    puts("\n-------------非递归后序遍历-------------");
    NoReLRD(t);
    puts("\n-------------层次遍历-------------");
    LayerOrder(t);

    return 0;
}
