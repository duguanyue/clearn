// 共享栈，即是两个栈使用同一段存储空间。
// 第一个栈从数组头开始存储，第二个栈从数组尾开始，两个栈向中间拓展。
// 当top1+1==top2或者top1==top2-1时，即staock overflow!.
// 与普通栈一样，共享栈出栈入栈的时间复杂度仍为O(1).
#include <stdio.h>
#define M 30
int stack[M];
int top0; //左边
int top1; //右边
void Init() {
    top0 = -1;
    top1 = M;
}
int IsFull() { return top0 == top1 - 1; }
int IsEmpty() { return top0 == -1 && top1 == M; }
// which 1代表左栈 2代表右栈
int Push(int item, int which) {
    if (IsFull()) {
        //栈已满
        return 0;
    }
    if (which == 0) {
        stack[++top0] = item;
    } else {
        stack[--top1] = item;
    }
    return 1;
}
int Pop(int *item, int which) {
    if (which == 0) {
        if (top0 == -1)
            return 0;
        *item = stack[top0--];
        return 1;
    } else {
        if (top1 == M)
            return 0;
        *item = stack[top1++];
        return 1;
    }
}
int main(int argc, char const *argv[]) {
    Init();
    int i = 0, c;
    while (!IsFull()) {
        if ((i & 1) == 0)
            Push(i, 0);
        else
            Push(i, 1);
        i++;
    }

    puts("栈中数据:");
    for (i = 0; i < M; i++) {
        printf("%-3d", stack[i]);
        if (i == top0)
            printf(" -> | <- ");
    }
    puts("\n左右轮流出栈:");
    i = 1;
    while (!IsEmpty()) {
        Pop(&c, i);
        printf("%-3d", c);
        i = !i;
    }

    return 0;
}
