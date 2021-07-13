/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#define QTD 4

int le_dados_previstos(int *vmat, int proj[][QTD]) //estou criando uma matriz
{
    FILE *arq;
    int i, j;
    arq = fopen("PREV.txt", "r");
    if (arq==NULL) {
        printf("Erro de abertura. \n");
        exit(0);
    }
    i=0;
    while (fscanf(arq, "%d", &vmat[i]) == 1) {
        for (j=0; j<QTD; j++)
            fscanf(arq, "%d", &proj[i][j]);
        i++;
    }
    fclose(arq);
    return i;
}

int busca(int elem, int *velem, int n)
{
    int i;
    for (i=0; i<n; i++)
        if(velem[i]==elem)
            return i;
    return -1;
}

void atualizaProjetos(int *vmat, int proj[][QTD], int n)
{
    FILE *arq;
    int matr, cod, dia, horas, pos;
    arq = fopen("MOV.txt", "r");
    if (arq==NULL) {
        printf("Erro de abertura. \n");
        exit(0);
    }
    while(fscanf(arq, "%d%d%d%d", &matr, &cod, &dia, &horas)==4) {
        pos = busca(matr, vmat, n);
        if (pos!=-1)
            proj[pos][cod-1]-=horas;
    }
    fclose(arq);
    return;
}

void gera_saida_arquivo (int *vmat, int proj[][QTD], int n)
{
    FILE *arq;
    int i, j, cont, prim;
    arq = fopen("REAL.txt", "w");
    if (arq==NULL) {
        printf("Erro de abertura. \n");
        exit(0);
    }
    prim=1;
    for (i=0; i<n; i++) {
        fprintf(arq, "%d ", vmat[i]);
        cont=0;
        for (j=0; j<QTD; j++) {
            fprintf(arq, "%4d ", proj[i][j]);
            if(proj[i][j]==0)
                cont++;
        }
        fprintf(arq, "\n");
        if (cont==QTD) {
            if (prim) {
                printf("funcionarios com previsao correta: \n");
                prim=0;
            }
            printf("%d ", vmat[i]);
        }
    }
    if (prim)
        printf("Nenhum funcionario com previsao correta");
    fclose(arq);
    return;
}

int main()
{
    int vMatr[MAX], vProjs[MAX][QTD], tot;
    tot = le_dados_previstos(vMatr, vProjs);
    atualizaProjetos(vMatr, vProjs, tot);
    gera_saida_arquivo (vMatr, vProjs, tot);
    return 0;
}
