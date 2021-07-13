/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define TOT 400

int contabiliza_respostas(int n) 
{
    int contador;
    int positivo = 0;
    for (contador = 0; contador < n; contador++) {
        int resposta;
        printf("Pergunta %d: Sim (1) ou Nao (0)?: ", contador+1);
        scanf("%d", &resposta);
        if (resposta == 1) {
            positivo++;
        }
    }
    return positivo;
}

void exibe_grupo(int nQuest, int quantSim)
{
    if (quantSim >= ((float)2/3)*nQuest) {
        printf("aluno pertence a grupo \"pro\"\n");
    }
    else if (quantSim <= ((float)1/3)*nQuest) {
        printf("aluno pertence a grupo \"contra\"\n");
    }
    else {
        printf("aluno pertence a grupo \"neutro\"\n");    
    }
}

int main()
{
    int nRespostas, contador;
    printf("Numero de respostas do questionario: ");
    scanf("%d", &nRespostas);
    for (contador = 0; contador < TOT; contador++) {
        int mat, nPos;
        printf("\nMatricula do aluno %d: ", contador+1);
        scanf("%d", &mat);
        nPos = contabiliza_respostas(nRespostas);
        exibe_grupo(nRespostas, nPos);
    }
    return 0;
}

