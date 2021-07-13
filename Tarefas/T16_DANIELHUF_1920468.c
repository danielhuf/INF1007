// T16 Programação II - Turma 33B
// Daniel Stulberg Huf - 1920468

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto
{
   int codigo;
   char nome[16];
   float preco;
   int quant;
   struct produto *prox;
};
typedef struct produto Produto;

FILE* openFile(const char* file, const char* mode)
{
    FILE* arq;
    arq = fopen(file, mode);
    if (arq==NULL)
        exit(0);
    return arq;
}

Produto* lst_cria()
{
    return NULL;
}

Produto* lst_insere (Produto* l, int cod, char* nom, float prec, int qtd)
{
    Produto* novo = (Produto*)malloc(sizeof(Produto));
    if (novo==NULL) exit(1);
    novo->codigo = cod;
    strcpy(novo->nome,nom);
    novo->preco = prec;
    novo->quant = qtd;
    novo->prox = l;
    return novo;
}

Produto* busca_lst (Produto* l, int codigo)
{
    Produto* p;
    for (p=l; p!=NULL && p->codigo!=codigo; p=p->prox);
    return p;
}

Produto* remove_lst(Produto *l, int cod)
{
    Produto *p, *q;
    q = NULL; 
    for (p=l; p!=NULL && p->codigo!=cod; p=p->prox)
        q=p;
    if (p==NULL)
        return l;
    if (q==NULL)
        l = p->prox;
    else
        q->prox = p->prox;
    free(p);
    return l;
}


void imprime_lst(Produto *l)
{
    Produto *p;
    printf("LISTA DE PRODUTOS:\n");
    for (p=l; p!=NULL; p=p->prox)
        printf("codigo: %d - nome: %s - preco: %.2f - quantidade em estoque: %d\n", p->codigo, p->nome, p->preco, p->quant);
    printf("\n");
}

void gerenciaEstoque (Produto* l)
{
    FILE* arq = openFile("movimento_estoque.txt", "r");
    char sinal, c, novoNome[16];
    int codigo, qtd, contador = 1;
    float novoPreco;
    Produto* pos;
    while (!feof(arq)) {
        fscanf(arq, "%c%d%d%c", &sinal, &codigo, &qtd, &c); //&c captura o '\n'
        printf("Movimentacao %d\n", contador++);
        pos = busca_lst(l, codigo);
        if (sinal == '+') {
            if (pos!=NULL)
                pos->quant += qtd;
            else {
                printf("Novo produto inserido. Nome do produto: ");
                scanf(" %[^\n]", novoNome);
                printf("Preco do produto: ");
                scanf("%f", &novoPreco);
                l = lst_insere(l, codigo, novoNome, novoPreco, qtd);
            }
        }
        else {
            if (pos==NULL)
                printf("Tentativa de retirada de produto com codigo %d inexistente na lista.\n", codigo);
            else if (qtd > pos->quant)
                printf("Pedido de retirada do produto com codigo %d maior que a quantidade em estoque.\n", codigo);
            else if (qtd == pos->quant)
                l = remove_lst(l, codigo);
            else 
                pos->quant -= qtd;
        }
        imprime_lst(l);
    }
    fclose(arq);
}

void libera_lst(Produto *l)
{
    Produto *t, *p = l;
    while (p!=NULL) {
        t = p->prox;
        free(p);
        p = t;
    }
}

int main()
{
    Produto* lProd;
    lProd = lst_cria();
    lProd = lst_insere(lProd, 122, "chocolate", 5.90, 21);
    lProd = lst_insere(lProd, 456, "ovo", 2.80, 30);
    lProd = lst_insere(lProd, 300, "maionese", 9.95, 17);
    lProd = lst_insere(lProd, 879, "laranja", 3.50, 4);
    lProd = lst_insere(lProd, 222, "alface", 8.75, 18);
    lProd = lst_insere(lProd, 990, "vinho", 75.00, 12);
    printf("INICIO\n");
    imprime_lst(lProd);
    printf("GERENCIANDO O ESTOQUE\n");
    gerenciaEstoque(lProd);
    libera_lst(lProd);
    return 0;
}


