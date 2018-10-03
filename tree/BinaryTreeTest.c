#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    char data;
    struct node *lChild, *rChild;
} Node, *Tree;
#define M 100
Tree STACK[M];
void Visit(Tree t) {
    if (t == NULL)
        printf("NULL");
    else
        printf("%c, ", t->data);
}
// 初始化Tree
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
//非递归前序
void NoReDLR(Tree tree) {
    Tree p = tree;
    int top = -1;
    while (p || top != -1) {
        while (p) {
            STACK[++top] = p;
            Visit(p);
            p = p->lChild;
        }
        p = STACK[top--];
        p = p->rChild;
    }
}
//非递归中序
void NoReLDR(Tree tree) {
    Tree p = tree;
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
//非递归后序
void NoReLRD(Tree tree) {
    Tree p = tree;
    int FLAG[M], flag, top = -1;
    while (p || top != -1) {
        while (p) {
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
int IsSimiliar(Tree t1, Tree t2) {
    if (t1 == NULL && t2 == NULL)
        return 1;
    return t1 && t2 && IsSimiliar(t1->lChild, t2->lChild) &&
           IsSimiliar(t1->rChild, t2->rChild);
}
int IsSame(Tree t1, Tree t2) {
    if (t1 == NULL && t2 == NULL)
        return 1;
    return t1 && t2 && t1->data == t2->data && IsSame(t1->lChild, t2->lChild) &&
           IsSame(t1->rChild, t2->rChild);
}
//计算二叉树中有多少度为1的点
int CountOne(Tree t1) {
    Tree p = t1;
    int top = -1, count = 0;
    while (p || top != -1) {
        //遍历过程中每个p都要入栈一次
        while (p) {
            printf("-> %c 是否度为 1 的点%d\n", p->data,
                   (p->lChild == NULL) ^ (p->rChild == NULL));
            count += (p->lChild == NULL) ^ (p->rChild == NULL);
            STACK[++top] = p;
            p = p->lChild;
        }
        p = STACK[top--];
        p = p->rChild;
    }
    return count;
}
//输出一个结点的所有祖先结点(递归方式)
int Ancestor(Tree tree, const char item) {
    if (tree == NULL)
        return 0;
    if (tree->data == item)
        return 1;
    int c = Ancestor(tree->lChild, item) || Ancestor(tree->rChild, item);
    if (c)
        Visit(tree);
    return c;
}
//输出一个结点的所有祖先结点(TODO 非递归方式)
int NoReAncestor(Tree tree, const char item) {
    //思想:利用后序遍历
    int FLAG[M], top = -1, flag;
    Tree p = tree;
    while (p || top != -1) {
        while (p && p->data != item) {
            STACK[++top] = p;
            FLAG[top] = 0;
            p = p->lChild;
        }
        if (p) {
            while (top != -1) {
                Visit(STACK[top--]);
            }
            break;
        }
        p = STACK[top];
        flag = FLAG[top--];
        if (flag) {
            p = NULL;
        } else {
            STACK[++top] = p;
            FLAG[top] = 1;
            p = p->rChild;
        }
    }
    return 0;
}
int main(int argc, char const *argv[]) {
    Tree t1 = ToTree("A(B(C,D(E(F,G),H(I))))@");
    puts("前序:");
    NoReDLR(t1);
    puts("\n中序:");
    NoReLDR(t1);
    puts("\n后序:");
    NoReLRD(t1);
    puts("\n-------------------------");
    Tree t2 = ToTree("A(B(C,D(E(G,F),H(I))))@");
    NoReDLR(t2);
    putchar('\n');
    printf("IsSimiliar : %d\n", IsSimiliar(t1, t2));
    printf("IsSame : %d\n", IsSame(t1, t2));
    printf("二叉树中度为1的点的个数 : %d\n", CountOne(t1));
    puts("\n递归求祖先结点");
    Ancestor(t1, 'F');
    puts("\n非递归求祖先结点");
    NoReAncestor(t1, 'F');
    return 0;
}
