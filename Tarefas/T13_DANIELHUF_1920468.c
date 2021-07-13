// T13 Programação II - Turma 33B
// Daniel Stulberg Huf - 1920468

#include <stdio.h>
#include <stdlib.h>

struct termo { 
    int coef; 
    int grau; 
};
typedef struct termo Termo;

int maiorNum (int n1, int n2)
{
    int maior;
    if (n1>=n2)
        maior = n1;
    else
        maior = n2;
    return maior;
}

int busca (Termo* pol, int n, int grau)
{
    int i;
    for (i=0; i<n; i++)
        if (pol[i].grau==grau)
            return i;
    return -1;
}

Termo* somaPolinomios (Termo* pol1, int n1, Termo* pol2, int n2, int* nResult)
{
    int i, pos1, pos2, s1, s2, j=0, nTermos = 0, maiorGrau = maiorNum(pol1[0].grau, pol2[0].grau);
    int vAuxCoefs[maiorGrau+1];
    Termo* polResult;
    for (i=maiorGrau; i>=0; i--) {
        pos1 = busca(pol1, n1, i);
        pos2 = busca(pol2, n2, i);
        if (pos1==-1)
            s1 = 0;
        else
            s1 = pol1[pos1].coef;
        if (pos2==-1)
            s2 = 0;
        else
            s2 = pol2[pos2].coef;
        vAuxCoefs[maiorGrau-i] = s1+s2;
    }
    for (i=0; i<=maiorGrau; i++)
        if (vAuxCoefs[i] != 0)
            nTermos++;
    if (nTermos==0) 
        nTermos=1;
    *nResult = nTermos;
    polResult = (Termo*)malloc(nTermos*sizeof(Termo));
    if (polResult == NULL)
        return NULL;
    for (i=0; i<=maiorGrau; i++) 
        if (vAuxCoefs[i] != 0) {
            polResult[j].coef = vAuxCoefs[i];
            polResult[j++].grau = maiorGrau-i;
        }
    return polResult;
}

void exibePol (Termo* pol, int n)
{
    int i;
    printf("\t");
    for (i=0; i<n-1; i++) 
        printf("%dx^%d + ", pol[i].coef, pol[i].grau);
    if (pol[n-1].grau==0)
        printf("%d", pol[n-1].coef);
    else
        printf("%dx^%d", pol[n-1].coef, pol[n-1].grau);
}

void exibeResult (Termo* pol1, int n1, Termo* pol2, int n2)
{
    int nTermos;
    Termo* polGerado;
    printf("Primeiro vetor:\n");
    exibePol(pol1,n1);
    printf("\nSegundo vetor:\n");
    exibePol(pol2,n2);
    polGerado = somaPolinomios(pol1, n1, pol2, n2, &nTermos);
    if (polGerado == NULL)
        printf("\nHouve problema de alocacao de memoria ao gerar o polinomio resultante.\n");
    else {
        printf("\nVetor soma:\n");
        exibePol(polGerado, nTermos);
        free(polGerado);
    }
}

int main()
{
    Termo p1[5] = {{6,11},{14,8},{9,7},{3,5},{4,1}};
    Termo p2[3] = {{2,10},{6,6},{2,5}};
    Termo p3[3] = {{-6,11},{-8,5},{-4,1}};
    Termo p4[5] = {{-6,11},{-14,8},{-9,7},{-3,5},{-4,1}};
    printf("Situacao 1: Vetor resultante com mais termos do que o vetor com maior numero de termos\n");
    exibeResult(p1, 5, p2, 3);
    printf("\n\nSituacao 2: Vetor resultante com menos termos do que o vetor com maior numero de termos\n");
    exibeResult(p1, 5, p3, 3);
    printf("\n\nSituacao 3: Vetor resultante com valor zero\n");
    exibeResult(p1, 5, p4, 5);
    return 0;
}

