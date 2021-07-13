/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

struct dados
{
	int idade;
	int peso;
};
typedef struct dados Dados;

int buscaPesoMenor (int n, Dados* vDad, int idade)
{
    int i;
    int ini=0;
    int fim = n-1;
    while (ini<=fim) {
        int meio = (ini+fim)/2;
        if (idade<vDad[meio].idade)
            fim = meio-1;
        else if (idade>vDad[meio].idade)
            ini = meio+1;
        else {
            for (i=meio; i>=0 && vDad[i].idade==idade; i--); //Estou pegando do meio para a esquerda, até chegar em uma idade diferente
            return i+1;
        }
    }
    return -1;
}

int main()
{
    int pos;
    Dados v[8] = {{18,60},{18,65},{20,30},{20,40},{20,65},{25,50},{30,40},{30,45}};
    pos = buscaPesoMenor(8, v, 20);
    if (pos==1)
        printf("Nao encontrado");
    else
        printf("%d", pos);
    return 0;
}
