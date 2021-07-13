// T6 Programação II - Turma 33B
// Daniel Stulberg Huf - 1920468

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int mediaVetor(int *vet, int tam, float *media)
{
    int i, soma=0, posProx=0;
    float distProx;
    for (i=0; i<tam; i++) 
        soma+=vet[i];
    *media = (float)soma/tam;   
    distProx = abs(vet[0]-(*media));
    for (i=0; i<tam; i++) 
        if (abs(vet[i]-(*media)) < distProx) {
            posProx = i;
            distProx = abs(vet[i]-(*media));
        }
    return posProx;
}

void iniciar_aleatorio(void)
{
    srand((unsigned int)time(NULL));
    rand(); rand(); rand();
}

int main()
{
    int *vet, indiceProx, i, tam=50;
    float med;
    vet = (int*)malloc(tam*sizeof(int));
    if (vet == NULL) 
        {printf("Ha problemas de alocacao de memoria"); exit(1);}
    else {
        iniciar_aleatorio();
        for (i=0; i<tam; i++)
            vet[i]=rand();
        indiceProx = mediaVetor(vet, tam, &med);
        printf("Elementos do vetor: \n");
        for (i=0; i<tam; i++) 
            printf("v[%d]=%d  ", i, vet[i]);
        printf("\nMedia = %.2f  Elemento mais proximo da media: v[%d]=%d", med, indiceProx, vet[indiceProx]);
        free(vet);
    }
    return 0;
}









