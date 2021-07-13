// T2 Programação II - Turma 33B
// Daniel Stulberg Huf - 1920468

#include <stdio.h>
#include <math.h>

double prob(int nlados, int n) {
    double p;
    p = ((float)1/nlados) * pow((float)(nlados-1)/nlados, n-1);
    return p;
}

int main(void) {
    int ndado;
    double result1, result2, result3;
    printf("Entre numero de lados: ");
    scanf("%d", &ndado);
    result1 = prob(ndado, 1);
    result2 = prob(ndado, 2);
    result3 = prob(ndado, 3);
    printf("Probabilidades para \"dado de %d lados\"\n", ndado);
    printf("1     2     3\n");
    printf("%5.3f %5.3f %5.3f", result1, result2, result3);
    return 0;
}




