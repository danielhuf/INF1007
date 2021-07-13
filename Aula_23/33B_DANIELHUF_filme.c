/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 12

typedef struct titulo Titulo;
struct titulo
{	char *nome;
	char *categoria;
	int   anoLancamento;
};

Titulo *tit_criar(char *nome, char *categoria, int ano)
{
    Titulo* novoItem;
    novoItem = (Titulo*)malloc(sizeof(Titulo));
    if (novoItem==NULL)
        return NULL;
    novoItem->nome = (char*)malloc((strlen(nome)+1)*sizeof(char));
    if (novoItem->nome==NULL)
        {printf("Houve erro de alocacao de memoria.");exit(1);}
    strcpy(novoItem->nome,nome);
    novoItem->categoria = (char*)malloc((strlen(categoria)+1)*sizeof(char));
    if (novoItem->categoria==NULL)
        {printf("Houve erro de alocacao de memoria.");exit(2);}
    strcpy(novoItem->categoria,categoria);
    novoItem->anoLancamento = ano;
    return novoItem;
}

void tit_imprimeTitulo(Titulo *t)
{
    printf("%d %-20s %-35s\n", t->anoLancamento, t->categoria, t->nome);
}

char *buscaMaisAntigo (int n, Titulo **v, char *categoria)
{
    int i, valor, meio, ini=0, fim=n-1;
    while(ini<=fim) {
        meio = (ini+fim)/2;
        valor = strcmp(categoria,v[meio]->categoria);
        if (valor<0)
            fim = meio-1;
        else if (valor>0)
            ini = meio+1;
        else {
            for (i=meio+1; i<n && strcmp(v[i]->categoria,categoria)==0; i++);
            return (v[i-1]->nome);
        }
    }
    return NULL;
}

int compara (Titulo *t, char *categoria, int ano)
{
    int r = strcmp(categoria, t->categoria);
    if (r!=0)
        return r; //se as categorias forem diferentes continua a busca
    return t->anoLancamento-ano; //se forem iguais, compara os anos (direita, esquerda ou o ano certo)
    /*
    if (r<0 || r==0 && t->ano>ano)
        return -1;
    else if (r>0 || r==0 && t->ano<ano)
        return 1;
    else
        return 0;
    */
}

Titulo *buscaBin (int n, Titulo **v, char* categoria, int ano)
{
    int i, valor, meio, ini=0, fim=n-1;
    while(ini<=fim) {
        meio = (ini+fim)/2;
        valor = compara(v[meio],categoria,ano);
        if (valor<0)
            fim = meio-1;
        else if (valor>0)
            ini = meio+1;
        else {
            return v[meio];
        }
    }
    return NULL;
}

int main()
{
    int i, ano=2008;
    char *maisAntigo;
    char *catDesejada = "animacao";
    Titulo *vp[N];
    Titulo *filme;
	vp[0] = tit_criar("Rio","animacao",2011);
	vp[1] = tit_criar("Meu Malvado Favorito","animacao",2010);
	vp[2] = tit_criar("Bolt - Supercao","animacao", 2008);
	vp[3] = tit_criar("Os Sem-Floresta","animacao", 2006);
    vp[4] = tit_criar("Shrek","animacao", 2001);
	vp[5] = tit_criar("O Homem do Futuro","comedia romantica", 2011);
	vp[6] = tit_criar("Sex and the City - O Filme","comedia romantica",2008);
	vp[7] = tit_criar("A Dona da Historia","comedia romantica",2004);
	vp[8] = tit_criar("Quebrando o Tabu","documentario", 2011);
    vp[9] = tit_criar("Senna","documentario",2010);
	vp[10] = tit_criar("Diario de Uma Busca","documentario", 2010);
	vp[11] = tit_criar("The Rolling Stones - Shine a Light","documentario", 2008);
	for (i=0; i<N; i++)
	    tit_imprimeTitulo(vp[i]);
	maisAntigo = buscaMaisAntigo(12, vp, "animacao");
	if (maisAntigo==NULL)
	    printf("\nNao foi encontrado titulo da categoria desejada");
	else
	    printf("\nanimacao - titulo mais antigo: %s", maisAntigo);
	//Endereço da struct que contem um certo filme e um certo ano.
	filme = buscaBin(N, vp, catDesejada, ano);
	if (filme==NULL)
	    printf("\nNao foi encontrado titulo da categoria desejada e ano desejado");
	else
	    printf("\n%s", filme->nome);
	for (i=0; i<N; i++) {
	    free(vp[i]->nome);
	    free(vp[i]->categoria);
	    free(vp[i]);
	}
    return 0;
}
