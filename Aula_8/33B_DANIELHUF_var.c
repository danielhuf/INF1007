/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int a, b;
    int *pa, *pb;
    pa = &a;
    pb = &b;
    printf("Forneca os valores de a e b: ");
    scanf("%d%d", pa, pb);
    printf("Os valores de a e b sao, respectivamente, %d e %d", a ,b);
    return 0;
}
