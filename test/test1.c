#include <stdio.h>
struct Demo {
    int (*func)(const char *);
};
int atoi(const char *s) {
    int n = 0;
    for (int i = 0; s[i]; i++) {
        n = n * 10 + (s[i] - '0');
    }
    return n;
}
int main(void) {
    char p[] = "12311";
    struct Demo demo;
    demo.func = &atoi;
    printf("%d\n", demo.func(p));

    return 0;
}