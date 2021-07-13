// T5 Programação II - Turma 33B
// Daniel Stulberg Huf - 1920468

#include <stdio.h>
#include <math.h>
#define VALORLADO 3.0
#define NLADOMAX 10

void calculaMedidas(float medida, int numL, float *perimetro, float *apotema, float *area)
{
    *perimetro = numL*medida;
    *apotema = medida/(2*tan((180/numL)*M_PI/180));
    *area = ((*perimetro) * (*apotema))/2;
}

int main()
{
    //No teste da funcao, defini o valor do lado como 3.0 e variei o numero de lados de 3 a 10
    float per, ap, ar;
    int i;
    printf("Valor do lado do poligono: %.1f", VALORLADO);
    printf("\nNumero de lados   Perimetro    Apotema    Area");
    for (i=3; i<=NLADOMAX; i++) {
        calculaMedidas(VALORLADO, i, &per, &ap, &ar);
        printf("\n%15d %11.1f %10.1f %7.1f", i, per, ap, ar);
    }
    return 0;
}







