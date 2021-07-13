// T12 Programação II - Turma 33B
// Daniel Stulberg Huf - 1920468

#include <stdio.h>
#include <stdlib.h>

typedef struct ponto {
    float x;
    float y;
} Ponto;

typedef struct retangulo {
    Ponto vInfEsq;
    float base;
    float altura;
} Retangulo;

Ponto calculaSupDir (Retangulo* ret) {
    Ponto vSupDir;
    vSupDir.x = ret->vInfEsq.x + ret->base;
    vSupDir.y = ret->vInfEsq.y + ret->altura;
    return vSupDir;
}

int main()  
{
    Retangulo* ret2;
    Ponto p1Sup, p2Sup;
    Retangulo ret1 = {{8.7, 1.3}, 2.2, 9};
    p1Sup = calculaSupDir(&ret1);
    printf("Dados do retangulo 1: \n");
    printf("\tVertice Inferior Esquerdo: (%.1f,%.1f)\n", ret1.vInfEsq.x, ret1.vInfEsq.y);
    printf("\tBase: %.1f\n", ret1.base);
    printf("\tAltura: %.1f\n", ret1.altura);
    printf("\tVertice Superior Direito: (%.1f,%.1f)\n", p1Sup.x, p1Sup.y);
    ret2 = (Retangulo*)malloc(sizeof(Retangulo));
    if (ret2==NULL)
        printf("Hove erro de alocacao de memoria");
    else {
        ret2->vInfEsq.x = -7.7;
        ret2->vInfEsq.y = -3;
        ret2->base = 4.3;
        ret2->altura = 2.8;
        p2Sup = calculaSupDir(ret2);
        printf("Dados do retangulo 2: \n");
        printf("\tVertice Inferior Esquerdo: (%.1f,%.1f)\n", ret2->vInfEsq.x, ret2->vInfEsq.y);
        printf("\tBase: %.1f\n", ret2->base);
        printf("\tAltura: %.1f\n", ret2->altura);
        printf("\tVertice Superior Direito: (%.1f,%.1f)\n", p2Sup.x, p2Sup.y);
        free(ret2);
    }
    return 0;
}





