//循环队列 使用数组
#include <stdio.h>
#define M 30
int queue[M];
int front, rear;
void Init() { front = rear = 0; }
int IsEmpty() { return front == rear; }
int enqueue(int item) {
    rear = (rear + 1) % M;
    if (rear == front)
        return 0; //队列已满
    queue[rear] = item;
    return 1;
}
int dequeue(int *item) {
    if (front == rear)
        return 0; // 空队列
    front = (front + 1) % M;
    *item = queue[front];
    return 1;
}
int main(int argc, char const *argv[]) {
    Init();
    int i, max = 7, c;
    while (1) {
        for (i = 1; i <= max; i++) {
            enqueue(i);
            puts("\n入队后:");
            for (int j = 0; j < M; j++) {
                printf("%d, ", queue[j]);
            }
            printf("\nfront:%d, rear:%d", front, rear);
        }
        putchar('\n');
        while (!IsEmpty()) {
            dequeue(&c);
            printf("%d, ", c);
        }
        printf("\nfront:%d, rear:%d", front, rear);
        puts("\n-----------------------");
        max += 5;
        if (max > 30)
            break;
    }

    return 0;
}
