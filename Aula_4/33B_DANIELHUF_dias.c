/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int ndias;
    printf("Número de dias decorridos do evento: ");
    scanf("%d", &ndias);
    printf("Duração do evento (%d dias): %d semana(s) e %d dia(s)", ndias, ndias/7, ndias%7);
    return 0;
}

