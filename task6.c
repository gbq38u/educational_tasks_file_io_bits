#include <stdio.h>
int main(void) {
    FILE *f;
    long long prev2, prev1, cur;
    int count = 0;
    int n, i;
    f = fopen("fib.txt", "r+");
    if (fscanf(f, "%lld", &prev2) == 1) {
        count = 1;
        if (fscanf(f, "%lld", &prev1) == 1) {
            count = 2;
            while (fscanf(f, "%lld", &cur) == 1) {
                prev2 = prev1;
                prev1 = cur;
                count++;}
        } else {
            prev1 = prev2;
            prev2 = 0;     
        }
    } 
    printf("В файле %d чисел\n", count);
    printf("Сколько дописать: ");
    scanf("%d", &n);
    fprintf(f, " ");  
    for (i = 0; i < n; i++) {
        long long next = prev1 + prev2;
        fprintf(f, "%lld ", next);
        prev2 = prev1;
        prev1 = next;
    }
    fclose(f);
    return 0;
}
