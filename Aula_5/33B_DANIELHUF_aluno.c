/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define TOT 20

int main()
{
    int n;
    float media, somanotas;
    somanotas = 0;
    for (n=1; n<=TOT; n++) {
        float nota;
        printf ("Nota do aluno %d: ", n);
        scanf ("%f", &nota);
        somanotas+=nota;
    }
    media = somanotas/TOT;
    printf ("Media da turma: %.2f\n", media);
    return 0;
}

