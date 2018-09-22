#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *left, *right;
} Node, *List;
//init list
List Init(){
    List head = (List)malloc(sizeof(Node));
    head->data = 0;


}
// insert item after x
int Insert(List list, const char *x, const char *item) {
    List p, q;
    q = list->right;
    while (q != list && q->data != x) {
        q = list->right;
    }
    if (q == list) {
        puts("no right node");
        return -1;
    }
    p = (List)malloc(sizeof(Node));
    p->data = item;
    p->left = q;
    p->right = q->right;
    q->right->left = p;
    q->right = p;
    return 1;
}
// remove item from list
int Delete(List list, const char *item) {
    List q = list->right;
    while (q != list && q->data != item) {
        q = list->right;
    }
    if (q == list) {
        puts("no right node");
        return -1;
    }
    q->left->right = q->right;
    q->right->left = q->left;
    free(q);
    return 1;
}
main(int argc, char const *argv[]) { return 0; }
