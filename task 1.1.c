#include <stdio.h>
int main(void) {
    int a[10];
    int i;

    printf("Введите 10 целых чисел:\n");
    for (i = 0; i < 10; i++) {
        if (scanf("%d", &a[i]) != 1) {
            printf("Ошибка ввода\n");
            return 1;
        }
    }
    printf("Вы ввели:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
/* 
обычный запуск
./array10
ввод из файла
./array10 < input.txt
 вывод в файл
./array10 > output.txt
и ввод, и вывод через файлы
./array10 < input.txt > output.txt
 */