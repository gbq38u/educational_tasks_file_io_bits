#include <stdio.h>

int my_read_int(void) {
    int c;
    int sign = 1;
    int x = 0;

    do {
        c = getchar();
        if (c == EOF) return 0;   
    } while (c == ' ' || c == '\n' || c == '\t' || c == '\r');

    if (c == '-') {
        sign = -1;
        c = getchar();
    } else if (c == '+') {
        c = getchar();
    }

    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = getchar();
    }

    return sign * x;
}
void my_write_int(int x) {
    char buf[20];
    int i = 0;
    int sign = 0;

    if (x == 0) {
        putchar('0');
        return;
    }

    if (x < 0) {
        sign = 1;
        x = -x;
    }
    while (x > 0 && i < (int)sizeof(buf) - 1) {
        int digit = x % 10;
        buf[i++] = (char)('0' + digit);
        x /= 10;
    }

    if (sign) {
        buf[i++] = '-';
    }

    while (i > 0) {
        putchar(buf[--i]);
    }
}

int main(void) {
    int a, b;
    printf("Введите два целых числа:\n");
    a = my_read_int();
    b = my_read_int();

    printf("Сумма: ");
    my_write_int(a + b);
    putchar('\n');
    return 0;
}
