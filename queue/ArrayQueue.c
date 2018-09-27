//使用数组来构造队列  font指向队头的前一个元素 rear指向队尾元素
#include <stdio.h>
#define M 100
int arr[M];
int front, rear;
//初始化
void Init() { front = rear = -1; }
//判断是否为空
int IsEmpty() { return front == rear; }
//入队
int enqueue(int item) {
    if (rear == M - 1)
        return 0; //队列已满
    arr[++rear] = item;
    return 1;
}
//出队
int dequeue(int *item) {
    if (IsEmpty())
        return 0; //空队列
    *item = arr[++front];
    return 1;
}
int main(int argc, char const *argv[]) {
    Init();
    for (int i = 0; i < 20; i++) {
        enqueue(i);
    }

    int c;
    while (!IsEmpty()) {
        dequeue(&c);
        printf("%-3d", c);
    }
    return 0;
}
