#include <stdio.h>
#define ROWS 20
#define COLS 5
int main(void) {
    FILE *f1, *f2, *f3;
    int i, j;
    int a[ROWS][COLS];
    int w;     
    int x;
    long line_size;   
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            a[i][j] = i * COLS + j + 1;  }
    }
    printf("ширина поля: ");
    f1 = fopen("table.txt", "w");
    if (!f1) {
        perror("table.txt");
        return 1;
    }
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            fprintf(f1, "%*d", w, a[i][j]);
        }
        fputc('\n', f1); 
    }
    rewind(f1);
    f2 = fopen("cols_seq.txt", "w");
    if (!f2) {
        perror("cols_seq.txt");
        fclose(f1);
        return 1;
    }
    printf("2 и 4 столбцы:\n");
    for (i = 0; i < ROWS; i++) {
        int val2 = 0, val4 = 0;
        for (j = 0; j < COLS; j++) {
            if (j == 1) val2 = x; 
            if (j == 3) val4 = x;  
        }
        fprintf(f2, "%d %d\n", val2, val4);
        printf("%d %d\n", val2, val4);
    }

    fclose(f2);
    line_size = COLS * w + 1;

    rewind(f1);

    f3 = fopen("cols_fseek.txt", "w");
    if (!f3) {
        perror("cols_fseek.txt");
        fclose(f1);
        return 1;
    }

    printf("\n2 и 4 столбцы (fseek):\n");
    for (i = 0; i < ROWS; i++) {
        long offset;
        int val2, val4;
        offset = i * line_size + 1L * w;     
        if (fscanf(f1, "%d", &val2) != 1) {
            printf("Ошибка чтения\n");
            fclose(f1);
            fclose(f3);
            return 1;
        }
        offset = i * line_size + 3L * w;      

        fprintf(f3, "%d %d\n", val2, val4);
        printf("%d %d\n", val2, val4);
    }
    fclose(f1);
    fclose(f3);
    return 0;
}
