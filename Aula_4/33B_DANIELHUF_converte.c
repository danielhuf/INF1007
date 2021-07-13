/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

float converte_moeda (float valor, float cotacao) {
    float conv = valor*cotacao;
    return conv;
}

int main()
{
    float r, d, e, cotD, cotE, tot;
    printf("Forneca o valor das compras em real, dolar e euro: ");
    scanf("%f%f%f", &r, &d, &e);
    printf("\nForneca o valor das cotacoes do dolar e do euro: ");
    scanf("%f%f", &cotD, &cotE);
    tot = r + converte_moeda(d,cotD) + converte_moeda(e,cotE);
    printf("\nValor total em reais a ser pago: R$%.2f", tot);
    return 0;
}
