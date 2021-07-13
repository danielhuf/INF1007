// T17 Programação II - Turma 33B
// Daniel Stulberg Huf - 1920468

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa
{
    char nome[16];
    struct pessoa *prox;
};
typedef struct pessoa Pessoa;

Pessoa* cria_fila()
{
    return NULL;
}

int verifica_fila_vazia (Pessoa *fila)
{
    return (fila==NULL);
}

void imprime_fila (Pessoa* fila)
{
    if (verifica_fila_vazia(fila)==0)
    {
        imprime_fila(fila->prox);
        printf("%s\n", fila->nome);
    }
    else
        printf("\n");
}

Pessoa* insere_fila (Pessoa* fila, char* nom)
{
    Pessoa* novaPessoa = (Pessoa*)malloc(sizeof(Pessoa));
    if (novaPessoa==NULL) {
        printf("Falta memoria para inserir um novo elemento da fila.\n");
        exit(1);
    }
    strcpy(novaPessoa->nome, nom);
    novaPessoa->prox = fila;
    printf("\nINSERCAO");
    imprime_fila(novaPessoa);
    return novaPessoa;
}

Pessoa* retira_fila (Pessoa* fila)
{
    Pessoa *p, *q=NULL;
    printf("\nREMOCAO");
    if (verifica_fila_vazia(fila)!=0)
        printf("\nA fila esta vazia. Nao ha como retirar mais elementos.\n");
    else {
        for (p=fila; p->prox!=NULL; p=p->prox) 
            q=p;
        if (q==NULL) {
            fila = NULL;
            printf("\nA fila esta vazia.\n");
        }
        else {
            q->prox = NULL;
            imprime_fila(fila);
        }
        free(p);
    }
    return fila;
}

void libera_fila (Pessoa* fila)
{
    Pessoa *t, *p = fila;
    while (p!=NULL) {
        t = p->prox;
        free(p);
        p = t;
    }
}

int main()
{
    Pessoa* filaPessoas;
    filaPessoas = cria_fila();
    filaPessoas = insere_fila(filaPessoas, "Daniel");
    filaPessoas = insere_fila(filaPessoas, "Jonas");
    filaPessoas = retira_fila(filaPessoas);
    filaPessoas = insere_fila(filaPessoas, "Michele");
    filaPessoas = insere_fila(filaPessoas, "Matheus");
    filaPessoas = retira_fila(filaPessoas);
    filaPessoas = insere_fila(filaPessoas, "Augusto");
    filaPessoas = retira_fila(filaPessoas);
    filaPessoas = insere_fila(filaPessoas, "Natalia");
    filaPessoas = retira_fila(filaPessoas);
    filaPessoas = retira_fila(filaPessoas);
    filaPessoas = retira_fila(filaPessoas);
    filaPessoas = retira_fila(filaPessoas);
    libera_fila(filaPessoas);
    return 0;
}