/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    float sal, tot;
    int n = 0;
    tot = 0;
    printf ("Digite o salario do funcionario %d: ", n+1);
    scanf ("%f", &sal);
    while (sal != 0) {
        tot += sal;
        n += 1;
        printf ("Digite o salario do funcionario %d: ", n+1);
        scanf ("%f", &sal);
    }
    printf ("\nTotal pago com salarios: R$%.2f", tot);
    printf ("\nSalario medio da empresa: R$%.2f", tot/n);
}

