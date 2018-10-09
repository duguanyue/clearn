#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MaxLen 20
typedef struct node {
    int data;
} Node, *Entity;
typedef Entity HashList[MaxLen];
int Hash(Entity entity) { return entity->data % MaxLen; }
int cmp(Entity e1, Entity e2) {
    if (e1 == NULL || e2 == NULL)
        return e1 == e2;
    return e1->data == e2->data;
}
int Insert(HashList list, Entity entity) {
    if (entity == NULL)
        return -1;
    int i, D;
    i = D = Hash(entity);

    while (list[D] != NULL && !cmp(list[D], entity)) {
        D = (D + 1) % MaxLen;
        if (D == i)
            return -1;
    }
    if (!cmp(list[D], entity))
        list[D] = entity;

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
        e = (Entity)malloc(sizeof(Node));
        e->data = c;
        f = Insert(list, e);
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