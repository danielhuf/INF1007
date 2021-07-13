// T7 Programação II - Turma 33B
// Daniel Stulberg Huf - 1920468

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FAIXAS 5

int* histograma(float *vetNotas, int nAlunos)
{
    int *vetQuant, i, pos;
    vetQuant = (int*)malloc(FAIXAS*sizeof(int));
    if (vetQuant == NULL)
        return NULL;
    else {
        for (i=0; i<FAIXAS; i++)
            vetQuant[i]=0;
        for (i=0; i<nAlunos; i++) {
            pos = vetNotas[i]/2;
            vetQuant[pos]=vetQuant[pos]+1;
        }
    }
    return vetQuant;
}

void iniciar_aleatorio(void)
{
    srand((unsigned int)time(NULL));
    rand(); rand(); rand();
}

float aleatorio(float a, float b)
{
    double r;
    r = (double)rand()/RAND_MAX;
    return (float)(a + r*(b-a));
}

int main()
{
    float *vetNotas;
    int i, *vetQuant, tam=40;
    vetNotas = (float*)malloc(tam*sizeof(float));
    if (vetNotas == NULL) 
        {printf("Ha problemas de alocacao de memoria"); exit(1);}
    else {
        iniciar_aleatorio();
        for (i=0; i<tam; i++)
            vetNotas[i] = aleatorio(0.0,10.0);
        printf("VETOR DE NOTAS: \n");
        for (i=0; i<tam; i++)
            printf("%.1f  ", vetNotas[i]);
        vetQuant = histograma(vetNotas, tam);
        if (vetQuant == NULL)
            {printf("Ha problemas de alocacao de memoria"); exit(1);}
        else {
            printf("\nHISTOGRAMA:\n");
            for (i=0; i<FAIXAS-1; i++)
                printf("[%d,%d):  %d\n", 2*i, (2*i)+2, vetQuant[i]);
            printf("[%d,%d]: %d", 2*i, (2*i)+2, vetQuant[i]);
            free(vetQuant);
        }
        free(vetNotas);
    }
    return 0;
}





