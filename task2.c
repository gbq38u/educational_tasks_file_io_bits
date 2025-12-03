#include <stdio.h>
#define MAX_LEN 1024 
int main(void) {
    FILE *f;
    char str[MAX_LEN];
    char *p = str; 
    int ch;
    f = fopen("input.txt", "r");
    if (f == NULL) {
        perror("input.txt");
        return 1;
    }
    while ((ch = fgetc(f)) != EOF && p - str < MAX_LEN - 1) {
        *p =(char)ch;  
        p++;     
    }
    *p = '\0';     
    fclose(f);
    printf("Строка:\n%s\n", str);
    return 0;
}
