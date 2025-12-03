#include <stdio.h>

void print_bin(int x) {
    unsigned int u = (unsigned int)x;
    int started = 0;
    for (int i = sizeof(int)*8 - 1; i >= 0; i--) {
        if (u & (1u << i)) {
            putchar('1');
            started = 1;
        } else if (started) {
            putchar('0'); }}
    if (!started) putchar('0'); }
int main(void) {
    int n;
    scanf("%d", &n);
    print_bin(n);
    return 0;
}
