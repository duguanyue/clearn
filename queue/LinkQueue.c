//使用键表构建队列
#include <stdio.h>
#include <stdlib.h>

#define M 30
typedef struct node {
    int data;
    struct node *next;
} Node, *LinkQueue;
// front 出队; rear 入队
LinkQueue front, rear;
int IsEmpty() { return front == NULL; }
//入队
int enqueue(int item) {
    LinkQueue p = (LinkQueue)malloc(sizeof(Node));
    p->data = item;
    p->next = NULL;
    if (front == NULL)
        front = p;
    else
        rear->next = p;
    rear = p;
    return 1;
}
//出队
int dequeue(int *item) {
    if (IsEmpty())
        return 0; //空队列
    LinkQueue p = front;
    *item = p->data;
    front = p->next;
    // if (front == rear)
    //     rear = NULL;
    free(p);
    return 1;
}
//销毁
void Destory() {
    while (front) {
        rear = front->next;
        printf("Destory rear 为 NULL : %d\n", rear == NULL);
        free(front);
        front = rear;
    }
}

int main(int argc, char const *argv[]) {
    int x = 8, c;
    while (1) {
        for (int i = 0; i < x; i++) {
            enqueue(i);
        }
        while (!IsEmpty()) {
            dequeue(&c);
            printf("%d, ", c);
        }
        putchar('\n');
        x += 3;
        if (x > M)
            break;
    }

    Destory();

    printf("\nfront为空:%d, rear为空:%d", front == NULL, rear == NULL);

    return 0;
}
