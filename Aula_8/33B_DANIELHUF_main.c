/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void le_dados(int *pn)
{
    scanf("%d", pn);
}

void maior(int n1, int n2, int *pmax)
{
    if (n1>n2){
        *pmax = n1;
    }
    else {
        *pmax = n2;
    }
}

float calculos(int n1, int n2, int *psoma){
    *psoma = n1+n2;
    return (float)(n1 + n2)/2;
}

int main (void)
{	int num1, num2, max, soma;
	printf("Informe um numero inteiro: ");
	le_dados (&num1); // captura um número do teclado
	printf("Informe outro numero inteiro: ");
	le_dados (&num2);
	maior(num1, num2, &max);  // armazena em Max o maior valor entre os fornecidos
	printf("O maior numero eh %d. ", max);
	printf("A media dos numeros eh %.1f. ", calculos(num1, num2, &soma)); // obs
	printf("A soma dos numeros eh %d. ", soma);
	return 0;
}

