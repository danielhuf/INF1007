/******************************************************************************
NOME COMPLETO: Daniel Stulberg Huf
MATRICULA PUC-Rio: 1920468
DATA: 02/12/2020
DISCIPLINA: INF1007 TURMA: 33B
DECLARACAO DE AUTORIA:
 Declaro que este documento foi produzido em sua totalidade por mim,
 sem consultas a outros alunos, professores ou qualquer outra pessoa.
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct cliente {
    char nome[16];
    int quantAcoes;
    int momento;
    struct cliente *prox;
} Cliente;

typedef struct fila {
    Cliente *ini;
    Cliente *fim;
    int n;
} Fila;

Fila* cria_fila () 
{
    Fila* f = (Fila*)malloc(sizeof(Fila));
    if (f==NULL) exit(1);
    f->ini = NULL;
    f->fim = NULL;
    f->n = 0;
    return f;
}

int fila_vazia (Fila *f)
{
    if(f->ini==NULL) 
        return 1;
    else 
        return 0;
}

void insere_fila (Fila *f, Cliente* clie)
{
    clie->prox = f->fim;
    f->fim = clie;
    if (f->ini==NULL)
        f->ini = clie;
    f->n++;
}

Cliente* retira_fila (Fila *f)
{
    Cliente *p, *a=NULL;
    if (fila_vazia(f)) {
        printf("Fila vazia.\n");
        exit(2);
    }
    for (p=f->fim; p!=f->ini; a=p, p=p->prox);
    f->ini = a;
    if (f->ini == NULL)
        f->fim == NULL;
    else
        f->ini->prox = NULL;
    f->n--;
    return p;
}

Cliente* primeiroCliente (Fila *f)
{
    return f->ini;
}

int tamFila (Fila* f)
{
    return f->n;
}

void libera_fila (Fila* f)
{
    free(f);
}

int gerenciaCompras (Fila* f, int fechamento, int* nAtendidos, float* porcentagem)
{
    int atendidos=0, totCompras=0, totClientes = tamFila(f);
    Cliente *p=primeiroCliente(f);
    Cliente* clieAtendido;
    while (!fila_vazia(f) && p->momento<fechamento) {
        clieAtendido = retira_fila(f);
        printf("Cliente %d (%s) atendido, quantidade acoes %d\n", atendidos+1, clieAtendido->nome, clieAtendido->quantAcoes);
        atendidos++;
        totCompras+=clieAtendido->quantAcoes;
        p = primeiroCliente(f);
    }
    *nAtendidos = atendidos;
    *porcentagem = ((float)atendidos/totClientes)*100;
    return totCompras;
}

int main()
{
    int i, totCompras, nProcessados, n, fechamento=70;
    float porCento;
    Fila* f = cria_fila();
    Cliente vClientes[5] = {{"Daniel", 2500, 30}, {"Antonio", 500, 45}, {"Juliana", 5000, 80}, {"Valeria", 2400, 120}, {"Armando", 3000, 150}};
    for(i=0; i<5; i++)
        insere_fila(f, &vClientes[i]);
    totCompras = gerenciaCompras(f, fechamento, &nProcessados, &porCento);
    printf("Fechamento: %d\n", fechamento);
    printf("Clientes atendidos: %d (%.1f%%)\n", nProcessados, porCento);
    printf("Total: %d\n", totCompras);
    n = tamFila(f);
    printf("\nLiberando a fila remanescente com %d cliente(s)", n);
    libera_fila(f);
    return 0;
}