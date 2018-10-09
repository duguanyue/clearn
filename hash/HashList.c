#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MaxLen 20
typedef struct node {
    int data;
} Node, *Entity;
typedef Entity HashList[MaxLen];
int Hash(int item) { return item % MaxLen; }
int Insert(HashList list, int item) {
    int i, D;
    i = D = Hash(item);

    while (list[D] != NULL && list[D]->data != item) {
        D = (D + 1) % MaxLen;
        if (D == i)
            return -1;
    }
    if (list[D] == NULL || list[D]->data != item) {
        Entity e = (Entity)malloc(sizeof(Node));
        e->data = item;
        list[D] = e;
    }
    return D;
}
int main(int argc, char const *argv[]) {
    HashList list;
    Entity e;
    srand(time(NULL));
    int i, c, f;
    for (i = 0; i < MaxLen; i++) {
        list[i] = NULL;
    }
    for (i = 0; i < 10; i++) {
        c = rand() % 100;
        f = Insert(list, c);
        printf("%d insert number (%d) result is %d\n", i, c, f);
    }

    puts("显示插入结果:");
    for (i = 0; i < MaxLen; i++) {
        e = list[i];
        if (e == NULL) {
            printf("%d is Null\n", i);
        } else {
            printf("%d is %d\n", i, e->data);
        }
    }
    return 0;
}