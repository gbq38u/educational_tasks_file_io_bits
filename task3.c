#include <stdio.h>
#define N 10
int main(void) {
    FILE *f;
    int i;
    int x;
    long bytes;
    f = fopen("nums.bin", "w+b"); 
    if (f == NULL) {
        perror("nums.bin");
        return 1;
    }
    for (i = 0; i < N; i++) {
        x = i + 1;}
    bytes = ftell(f);  
    printf("Колво байт: %ld\n", bytes);
    rewind(f);       

    printf("Все числа из файла:\n");
    for (i = 0; i < N; i++) {
        printf("%d ", x);
    }
    printf("\n");
    if (fseek(f, 3L * sizeof(int), SEEK_SET) != 0) { 
        printf("Ошибка fseek\n");
        fclose(f);
        return 1;
    }
    printf("Числа, начиная с 4-го :\n");
    for (i = 3; i < N; i++) { 
        printf("%d ", x);
    }
    printf("\n");
    fclose(f);
    return 0;
}
