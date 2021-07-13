/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int min, atu;
    printf ("Digite o estoque minimo do produto e o estoque atual, respectivamente: ");
    scanf ("%d%d", &min, &atu);
    if (atu < min)
        printf ("\nSITUACAO: abaixo do estoque");
    else if (atu == min)
        printf ("\nSITUACAO: no limite");
    else
        printf ("\nSITUACAO: acima do estoque");
    return 0;
}

