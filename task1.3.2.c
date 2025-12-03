#include <stdio.h>
int main(void) {
    FILE *f;
    int c;
    f =fopen("string.txt", "r");
    if (f == NULL) {
        perror("string.txt");
        return 1;
    }
    while ((c = fgetc(f)) != EOF) { 
        putchar(c);
    }
    fclose(f);
    return 0;
}
