/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int mat1, mat2;
    float med1, med2;
    printf ("Digite a matricula e media do Aluno 1: ");
    scanf ("%d%f", &mat1, &med1);
    printf ("\nDigite a matricula e media do Aluno 2: ");
    scanf ("%d%f", &mat2, &med2);
    if (med1 > med2)
        printf ("\nAluno com maior media: %d", mat1);
    else if (med2 > med1)
        printf ("\nAluno com maior media: %d", mat2);
    else
        printf ("\nAlunos possuem a mesma media: matriculas %d e %d", mat1, mat2);
    return 0;
}
