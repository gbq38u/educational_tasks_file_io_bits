#include <stdio.h>
int main(void) {
    FILE *f;
    char ch;
    int i;
    f = fopen("chars.txt", "w");
    if (f == NULL) {
        perror("chars.txt");
        return 1;
    }
    for (i = 0; i < 10;i++) {
        if (scanf(" %c",&ch) != 1) { 
            fclose(f);
            return 1;
        }
        fputc(ch,f); 
    }
    fclose(f);
    return 0;
}
