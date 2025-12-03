#include <stdio.h>

int main(void) {
    FILE *f;
    double x;
    int i;
    f = fopen("numbers.txt", "w");
    printf("Введите 10 чисел:\n");
    for (i = 0; i < 10; i++) {
        if (scanf("%lf", &x) != 1) {
            fclose(f);
            return 1;
        }
        fprintf(f, "%g ", x);   
    }
    fclose(f);
    return 0;
}
