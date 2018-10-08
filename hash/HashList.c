#include <stdio.h>
#include <stdlib.h>
#define MaxLen 100
typedef int HashList[MaxLen];
int Hash(int value) { return value % MaxLen; }
int Insert(HashList list, int value) {
    int i, D;
    i = Hash(value);
}
int main(int argc, char const *argv[]) { return 0; }