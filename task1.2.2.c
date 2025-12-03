#include <stdio.h>
int main(void) {
    FILE *f;
    double x;
    f = fopen("numbers.txt", "r");
    printf("Числа из файла:\n");
    while (fscanf(f, "%lf", &x) == 1) {  
        printf("%g ", x);
    }
    printf("\n");
    fclose(f);
    return 0;
}
