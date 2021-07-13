/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    float comp, larg;
    printf("Comprimento e largura da sala: ");
    scanf("%f%f", &comp, &larg);
    printf("Area da sala: %.2f - Perimetro da sala: %.2f", comp*larg, 2*comp+2*larg);
    return 0;
}



