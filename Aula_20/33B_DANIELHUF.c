/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct avaliacao
{	
    float valorVendidoNoMes;
	int	numeroDeFaltas;
};
typedef struct avaliacao Avaliacao;

struct vendedor
{ 	
    int inscricao;
	char nome[51];
	float salario_base;
	Avaliacao aval;
};
typedef struct vendedor Vendedor;

float calculaExtra (Avaliacao aval)
{
    if (aval.numeroDeFaltas<2) {
        if (aval.valorVendidoNoMes>2000)
            return 180;
    }
    else if (aval.numeroDeFaltas<4) {
        if (aval.valorVendidoNoMes>2000)
            return 150;
    }
    else if (aval.numeroDeFaltas<6) {
        if (aval.valorVendidoNoMes>5000)
            return 120;
    }
    return 0;
}

float calculaVetorTotalDaFolha (int n, Vendedor* vVend)
{
    int i;
    float salario, tot=0;
    for (i=0; i<n; i++) {
        salario = vVend[i].salario_base + calculaExtra(vVend[i].aval);
        tot += salario;
    }
    return tot;   
}

int* obtemRelacaoDemitidos (int n, Vendedor* vVend, int* nDemitidos)
{
    int* vDemitidos;
    int i, demitidos = 0, j = 0;
    for (i=0; i<n; i++) {
        if (vVend[i].aval.numeroDeFaltas>=10)
            demitidos++;
    }
    *nDemitidos = demitidos;
    if (demitidos==0)
        return NULL;
    vDemitidos = (int*)malloc(demitidos*sizeof(int));
    if (vDemitidos==NULL)
        return NULL;
    for (i=0; i<n; i++) {
        if (vVend[i].aval.numeroDeFaltas>=10) 
            vDemitidos[j++] = vVend[i].inscricao;
    }
    return vDemitidos;
}

char* obtemMelhorVendedor (int n, Vendedor* vVend) {
    int i;
    int posMelhor = 0;
    for (i=1; i<n; i++) {
        if (vVend[i].aval.valorVendidoNoMes>vVend[posMelhor].aval.valorVendidoNoMes) 
            posMelhor = i;
    }
    return vVend[posMelhor].nome;
}

int main (void)
{
    Vendedor vVendedor[10]= {{1, "Ana Silva", 1000,{3000,1}},
    {2, "Pedro Duarte",2000,{3010,3}},
    {3, "Joao Filho", 1000,{3020,4}},
    {4, "Maria Gomes", 3000,{3030,15}},
    {5, "Silvio Lins", 1000,{6000,15}},
    {6, "Marcia Morais",2000,{6010,3}},
    {7, "Bruno Rodrigues",3000,{6020,4}},
    {8, "Thais Silva", 4000,{6030,7}},
    {9, "Ricardo Costa", 5000,{3040,7}},
    {10, "Julia Neves", 10000,{1000,0}}};
    float totalPags;
    int nDemitidos, i;
    int *vDemitidos;
    char* melhorVendedor;
    totalPags = calculaVetorTotalDaFolha(10, vVendedor);
    printf("Total gasto com a folha de pagamentos: R$%.2f\n", totalPags);
    vDemitidos = obtemRelacaoDemitidos(10, vVendedor, &nDemitidos);
    if (vDemitidos==NULL) {
        if (nDemitidos == 0)
            printf("Nenhum funcionario sera demitido.\n");
        else 
            printf("Falta memoria.\n");
    }
    else {
            printf("Funcionarios com mais de 10 faltas: \n");
            for (i=0; i<nDemitidos; i++)
                printf("%d\n", vDemitidos[i]);
            free(vDemitidos);
    }
    melhorVendedor = obtemMelhorVendedor(10, vVendedor);
    printf("Melhor Vendedor da Loja: %s", melhorVendedor);
return 0;
}


