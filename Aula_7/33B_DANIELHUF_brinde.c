/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int nBrindes, dia, mes;
    int contador = 0;
    printf("Informe a quantidade de brindes a serem distribuidos: ");
    scanf("%d", &nBrindes);
    while (contador < nBrindes) {
        printf("Ola! Informe o dia e o mes do seu aniversario: ");
        scanf("%d%d", &dia, &mes);
        if (dia%mes == 0) {
            printf("PARABENS\n");
            contador++;
        }
    }
    printf("PROMOCAO ENCERRADA");
    return 0;
}
