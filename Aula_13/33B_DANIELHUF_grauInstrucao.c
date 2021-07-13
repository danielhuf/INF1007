/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define TOT 7

void zeraVetor(int *v, int n)
{
    int i;
    for (i=0; i<n; i++)
        v[i]=0;   //tambem pode colocar *(v+i)=0
    return;
}

void exibeMediaGraus(int *vetSomaIdadesGraus, int *vetNPessoasGraus, int nGraus)
{
    int i;
    float media;
    printf("Media das idades por grau\n");
    for (i=0; i<nGraus; i++) {
        if (vetNPessoasGraus[i]!=0)
            media = (float)vetSomaIdadesGraus[i]/vetNPessoasGraus[i];
        else
            media = 0;
        printf("Grau %d: %.1f\n", i+1, media);
    }
}

void exibeMaisVelhoGraus(int *vetMaisVelhoGraus, int nGraus)
{
    int i;
    printf("\nIdade dos mais velhos por grau\n");
    for (i=0; i<nGraus; i++) 
        printf("Grau %d: %d anos\n", i+1, vetMaisVelhoGraus[i]);
}

int main()
{
    int gInstr, idade, vetSomaIdadesGraus[TOT], vetNPessoasGraus[TOT], vetMaisVelhoGraus[TOT], nPessoas=0;
    zeraVetor(vetSomaIdadesGraus, TOT);
    zeraVetor(vetNPessoasGraus, TOT);
    zeraVetor(vetMaisVelhoGraus, TOT);
    printf("Grau de instrucao da pessoa %d: ", nPessoas+1);
    scanf("%d", &gInstr);
    while (gInstr!=0) {
        printf("Idade da pessoa %d: ", nPessoas+1);
        scanf("%d", &idade);
        nPessoas++;
        vetNPessoasGraus[gInstr-1]++;
        vetSomaIdadesGraus[gInstr-1]+=idade;
        if (idade > vetMaisVelhoGraus[gInstr-1])
            vetMaisVelhoGraus[gInstr-1] = idade;
        printf("Grau de instrucao da pessoa %d: ", nPessoas+1);
        scanf("%d", &gInstr);
    }
    exibeMediaGraus(vetSomaIdadesGraus, vetNPessoasGraus, TOT);
    exibeMaisVelhoGraus(vetMaisVelhoGraus, TOT);
    return 0;
}

