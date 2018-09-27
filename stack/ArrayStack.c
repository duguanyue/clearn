//栈
#include <stdio.h>
#define M 10
int stack[M];
int top;
void Init() { top = -1; }
int isEmpty() { return top == -1; }
int isFull() { return top == M - 1; }
int Pop(int *c) {
    if (isEmpty())
        return 0;
    *c = stack[top--];
    return 1;
}
int Push(int item) {
    if (isFull())
        return 0;
    stack[++top] = item;
    return 1;
}
int Peep(int *c) {
    if (isEmpty())
        return 0;
    *c = stack[top];
    return 1;
}
int main(int argc, char const *argv[]) {
    Init();
    int c;
    int i = 0;
    while (!isFull()) {
        Push(i++);
    }

    while (!isEmpty()) {
        Pop(&c);
        printf("%-3d", c);
    }

    return 0;
}
