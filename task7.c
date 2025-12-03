#include <stdio.h>
#include <stdlib.h>
int main(void) {
    const char *fname = "numbers.txt"; 
    FILE *f;
    double *a = NULL; 
    int n = 0;          
    int cap = 0;        
    double x;
    int i;
    f = fopen(fname, "r");
    while (fscanf(f, "%lf", &x) == 1) {
        if (n == cap) {
            cap = (cap == 0) ? 16 : cap * 2;      
            a = realloc(a, cap * sizeof(double)); 
        }
        a[n++] = x;
    }
    fclose(f);
    int imin = 0, imax = 0;
    double min = a[0], max = a[0];
    for (i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
            imin = i;}
        if (a[i] > max) {
            max = a[i];
            imax = i;}}
    double tmp = a[imin];
    a[imin] = a[imax];
    a[imax] = tmp;
    f = fopen(fname, "w");
    for (i = 0; i < n; i++) {
        fprintf(f, "%g ", a[i]);}
    fclose(f);
    free(a);
    return 0;
}
