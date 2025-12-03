#include <stdio.h>
#include <string.h>

int main(void) {
    char filename[256];
    char buf[256];
    FILE *f;
    int c;
    printf("Введите имя файла:\n");
    filename[strcspn(filename, "\n")] = '\0';
    f = fopen(filename, "a");
    if (f == NULL) {
        perror("fopen");
        return 1;
    }
    printf("Вводите строки для дописи в файл.\n");
    printf("Чтобы закончить, введите строку:конец файла\n");
    while (1) {
        buf[strcspn(buf, "\n")] = '\0';
        if (strcmp(buf, "конец файла") == 0) {
            break;
        }
        fprintf(f, "%s\n", buf);
    }
    fclose(f);
    printf("Данные дописаны в файл %s\n", filename);
    f = fopen(filename, "r");
    if (f == NULL) {
        perror("fopen");
        return 1;
    }
    printf("\nСодержимое файла %s:\n", filename);
    while ((c = fgetc(f)) != EOF) {
        putchar(c);
    }
    fclose(f);
    return 0;
}
