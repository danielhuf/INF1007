/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define ALUNO 100

void exibeParabens(float media)
{
    if (media > 9.0) {
        printf("\nParabens!");
    }
}

void exibeSituacao(float media)
{
    if (media >= 5.0) {
        printf("aprovado");
        exibeParabens(media);
    }
    else if (media < 3.0) {
        printf("reprovado");
    }
    else {
        printf("em final");
    }
}

int main()
{
    int contador, mat;
    float n1, n2, med;
    for (contador = 0; contador < ALUNO; contador++){
        printf("\nForneca a matricula do aluno %d: ", contador+1);
        scanf("%d", &mat);
        printf("Forneca as duas notas: ");
        scanf("%f%f", &n1, &n2);
        med = (n1+n2)/2;
        printf("Matricula: %d - Media: %.2f - Situacao: ", mat, med);
        exibeSituacao(med);
    }
    return 0;
}

