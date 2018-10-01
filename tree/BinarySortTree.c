/*
 *二叉排序树
 *将数组写为二叉排序树的形式,并用中序遍历,这样得出排序后的元素
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *lChild, *rChild;
} Node, *Tree;
#define M 8
void Visit(Tree t) {
    if (t == NULL)
        printf("NULL");
    else
        printf("%d, ", t->data);
}
Tree Insert(Tree tree, int item) {
    if (tree == NULL) {
        tree = (Tree)malloc(sizeof(Node));
        tree->data = item;
        tree->lChild = NULL;
        tree->rChild = NULL;
        return tree;
    }
    if (item < tree->data) {
        tree->lChild = Insert(tree->lChild, item);
    } else {
        tree->rChild = Insert(tree->rChild, item);
    }
    return tree;
}
//中序
void Show(Tree tree) {
    if (tree != NULL) {
        Show(tree->lChild);
        Visit(tree);
        Show(tree->rChild);
    }
}
//中序无递归
void NoReShow(Tree tree) {
    Tree STACK[M], p = tree;
    int top = -1;
    while (p != NULL || top != -1) {
        while (p) {
            STACK[++top] = p;
            p = p->lChild;
        }
        p = STACK[top--];
        Visit(p);
        p = p->rChild;
    }
}
void LayerOrder(Tree tree) {
    Tree QUEUE[M], p;
    int front = -1, rear = 0;
    QUEUE[rear] = tree;
    while (front < rear) {
        p = QUEUE[++front];
        Visit(p);
        if (p->lChild)
            QUEUE[++rear] = p->lChild;
        if (p->rChild)
            QUEUE[++rear] = p->rChild;
    }
}
Tree Search(Tree tree, int item) {
    if (tree == NULL || tree->data == item)
        return tree;
    if (tree->data > item)
        return Search(tree->lChild, item);
    return Search(tree->rChild, item);
}
Tree NoReSearch(Tree tree, int item) {
    Tree p = tree;
    while (p != NULL) {
        if (p->data == item) {
            return p;
        }
        if (p->data > item) {
            p = p->lChild;
        } else {
            p = p->rChild;
        }
    }
    return NULL;
}
int main(int argc, char const *argv[]) {
    // create
    int arr[M] = {5, 10, 5, 20, 17, 12, 19, 2};
    Tree t = NULL;
    for (int i = 0; i < M; i++)
        t = Insert(t, arr[i]);

    puts("\n中序");
    Show(t);
    puts("\n中序无递归");
    NoReShow(t);
    puts("\n递归查询10的位置");
    int n = 10;
    Tree p = Search(t, n);
    Visit(p);
    puts("\n非递归查询10的位置");
    p = NoReSearch(t, n);
    Visit(p);
    puts("\n递归查询7的位置");
    n = 7;
    p = Search(t, n);
    Visit(p);
    puts("\n非递归查询7的位置");
    p = NoReSearch(t, n);
    Visit(p);
    puts("\n层次遍历");
    LayerOrder(t);
    return 0;
}
