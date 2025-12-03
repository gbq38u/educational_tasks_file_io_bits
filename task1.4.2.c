#include <stdio.h>
int main(void) {
    FILE *f;
    int c;
    f = fopen("chars.txt","r");
    if (f == NULL) {
        perror("chars.txt");
        return 1;
    }
    while ((c = fgetc(f))!= EOF) {
        putchar(c);
    }
    printf("\n");
    fclose(f);
    return 0;
}
