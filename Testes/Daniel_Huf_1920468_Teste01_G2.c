/******************************************************************************
NOME COMPLETO: Daniel Stulberg Huf
MATRICULA PUC-Rio: 1920468
DATA: 24/11/2020
DISCIPLINA: INF1007 TURMA: 33B
DECLARACAO DE AUTORIA:
 Declaro que este documento foi produzido em sua totalidade por mim,
 sem consultas a outros alunos, professores ou qualquer outra pessoa.
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAX 8

typedef struct cliente {
    int nExames;
    int* vResults;
} Cliente;

FILE* openFile(const char* file, const char* mode)
{
    FILE* arq;
    arq = fopen(file, mode);
    if (arq==NULL)
        exit(1);
    return arq;
}

Cliente* criaCliente (int* vResultados, int tam)
{
    int i;
    Cliente* clie;
    clie = (Cliente*)malloc(sizeof(Cliente));
    if (clie==NULL)
        return NULL;
    clie->nExames = tam;
    clie->vResults = (int*)malloc(tam*sizeof(int));
    if (clie->vResults==NULL)
        return NULL;
    for (i=0; i<tam; i++)
        clie->vResults[i] = vResultados[i];
    return clie;
}

void imprimeVetor (Cliente** vClientes, int n)
{
    int i, j;
    for (i=0; i<n; i++) {
        printf("Cliente %d: ", i);
        for (j=0; j<vClientes[i]->nExames; j++)
            printf("%d ", vClientes[i]->vResults[j]);
        printf("\n");
    }
}

void imprimeMenoresExames (Cliente** vClientes, int n, int menorExame)
{
    int i, j, contador=0;
    for (i=0; i<n; i++) {
        if (vClientes[i]->nExames==menorExame) {
            if (contador==0)
                printf("\nClientes com o menor numero de exames:\n");
            printf("Cliente %d: ", i);
            for (j=0; j<vClientes[i]->nExames; j++)
                printf("%d ", vClientes[i]->vResults[j]);
            printf("\n");
            contador++;
        }
    }
}

void liberaMemoria (Cliente** vClientes, int n)
{
    int i;
    for (i=0; i<n; i++) {
        free(vClientes[i]->vResults);
        free(vClientes[i]);
    }
    free (vClientes);
    printf("\nMemoria Liberada!");
}

int main()
{
    char string[10];
    int totClientes, c, pos, contaExames, vAuxResultados[MAX], menosExames=MAX+1;
    Cliente** vClientes;
    FILE *arq = openFile("Daniel_Huf_1920468_Teste01_G2.txt", "r");
    fscanf(arq, "%s%d", string, &totClientes);
    vClientes = (Cliente**)malloc(totClientes*sizeof(Cliente*));
    if (vClientes==NULL)
        exit(2);
    c = fgetc(arq);   //Estou capturando o \n referente à primeira linha do arquivo
    while (!feof(arq)) {
        fscanf(arq, "%d", &pos);
        contaExames=0;
        c = fgetc(arq);
        for (; c!='\n' && c!=EOF; c=fgetc(arq)) {
            fscanf(arq, "%d", &vAuxResultados[contaExames++]);
        }
        vClientes[pos] = criaCliente(vAuxResultados, contaExames);
        if (vClientes[pos]==NULL)
            exit(3);
        if (contaExames<menosExames)
            menosExames = contaExames;
    }
    fclose(arq);
    imprimeVetor(vClientes, totClientes);
    imprimeMenoresExames(vClientes, totClientes, menosExames);
    liberaMemoria(vClientes, totClientes);
    return 0;
}

