#include <stdio.h>
int main(void) {
    FILE *f;
    char buf[256];
    f = fopen("string.txt", "w");
    if (f == NULL) {
        perror("string.txt");
        return 1;
    }
    fputs(buf, f);  
    fclose(f);
    return 0;
}
