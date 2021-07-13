/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    float nota1, nota2, media;
    printf("Insira sua nota 1 e sua nota 2: ");
    scanf("%f%f", &nota1, &nota2);
    media = (float)(3*nota1 + 7*nota2)/10;
    printf ("Media: %.2f", media);
    return 0;
}



