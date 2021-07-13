/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define CAND 10

void min_max(int *vetor, int tot, int *posMenor, int *posMaior)
{
    int i;
    int posMen = 0;
    int posMai = 0;
    for (i=0; i<tot; i++){
        if (vetor[i] > vetor[posMai])
            posMai = i;
        if (vetor[i] < vetor[posMen])
            posMen = i;
    }
    *posMenor = posMen;
    *posMaior = posMai;
}

void inicializaVotos(int *vetor, int tot)
{
    int i;
    for (i=0; i<tot; i++)
        vetor[i] = 0;
}

int busca(int *vetor, int tot, int cod)
{
    int i;
    for (i=0; i<tot; i++) {
        if (cod == vetor[i])
            return i;
    }
}

int main()
{
    int totAlunos, vReis[CAND], vVotosReis[CAND], vRainhas[CAND], vVotosRainhas[CAND], i, cod, contador, codRei, codRainha, pos, posMenorRei, posMaiorRei, posMenorRainha, posMaiorRainha;
    printf("Forneca a quantidade de alunos da escola: ");
    scanf("%d", &totAlunos);
    for (i=0; i<CAND; i++) {
        printf("Forneca o codigo do candidato %d a rei: ", i+1);
        scanf("%d", &cod);
        vReis[i] = cod;
        vRainhas[i] = i+1;
    }
    inicializaVotos(vVotosReis, CAND);
    inicializaVotos(vVotosRainhas, CAND);
    for (contador=0; contador<totAlunos; contador++) {
        printf("ALUNO %d-> Forneca o codigos do rei e rainha, respectivamente, que deseja escolher: ", contador+1);
        scanf("%d%d", &codRei, &codRainha);
        vVotosRainhas[codRainha-1] = vVotosRainhas[codRainha-1]+1;
        pos = busca(vReis, CAND, codRei);
        vVotosReis[pos]++;
    }
    min_max(vVotosReis, CAND, &posMenorRei, &posMaiorRei);
    min_max(vVotosRainhas, CAND, &posMenorRainha, &posMaiorRainha);
    printf("REI DA ESCOLA: %d - RAINHA DA ESCOLA: %d", vReis[posMaiorRei], vRainhas[posMaiorRainha]);
    printf("\nLANTERNINHO DA ESCOLA: %d - LANTERNINHA DA ESCOLA: %d", vReis[posMenorRei], vRainhas[posMenorRainha]);
    return 0;
}



