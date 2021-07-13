/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
#define QTD 3

int le_arq_contas (char vCliente[][26], float vConta[][QTD])
{
    FILE *arq;
    int i, j;
    arq = fopen("contas.txt", "r");
    if (arq==NULL) {
        printf("Erro de leitura. \n");
        exit(0);
    }
    i=0;
    while (fscanf(arq, " %[^\n]", vCliente[i])==1) {
        for (j=0; j<QTD; j++)
            fscanf(arq, "%f", &vConta[i][j]);
        i++;
    }
    fclose(arq);
    return i;
}

int busca(char *elem, char velem[][26], int n)
{
    int i;
    for (i=0; i<n; i++)
        if(strcmp(velem[i],elem)==0)
            return i;
    return -1;
}

void atualiza_dados (char vCliente[][26], float vConta[][QTD], int n)
{
    FILE *arq;
    int conta, pos;
    char cliente[26];
    float valor;
    char tipo;
    arq = fopen("movimentacoes.txt", "r");
    if (arq==NULL) {
        printf("Erro de leitura. \n");
        exit(0);
    }
    while (fscanf(arq, " %[^\n]", cliente)==1) {
        pos = busca(cliente, vCliente, n);
        fscanf(arq, " %c%d", &tipo, &conta);
        if (tipo == 't')
            vConta[pos][conta-1]=0;
        else {
            fscanf(arq, "%f", &valor);
            if (tipo == 'r')
                vConta[pos][conta-1]-=valor;
            else
                vConta[pos][conta-1]+=valor;
        }
    }
    fclose(arq);
    return;
}

void gera_arquivo_atual (char vCliente[][26], float vConta[][QTD], int n)
{
    FILE *arq;
    int i, j;
    arq = fopen("ATUAL.txt", "w");
    if (arq==NULL) {
        printf("Erro de abertura. \n");
        exit(0);
    }
    for (i=0; i<n; i++){
        fprintf(arq, "%s\n", vCliente[i]);
        for (j=0; j<QTD; j++)
            fprintf(arq, "%.2f   ", vConta[i][j]);
            fprintf(arq, "\n");
    }
    fclose(arq);
}

int main()
{
    int tot;
    float vContas[MAX][QTD];
    char vClientes[MAX][26];
    tot = le_arq_contas(vClientes, vContas);
    atualiza_dados(vClientes, vContas, tot);
    gera_arquivo_atual(vClientes, vContas, tot);
    return 0;
}
