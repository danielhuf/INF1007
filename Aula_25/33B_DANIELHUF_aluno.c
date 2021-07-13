/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno 
{ 
  int mat; 
  char nome[21]; 
  float nota; 
  char sexo; 
  struct aluno *prox; 
}; 
typedef struct aluno Aluno; 

Aluno* lst_cria()
{
    return NULL;
}

Aluno* lst_insere(Aluno *l, int matr, char* nom, float nota, char sex)
{
    Aluno* novo = (Aluno*)malloc(sizeof(Aluno));
    if (novo==NULL) exit(0);
    novo->mat = matr;
    strcpy(novo->nome,nom);
    novo->nota = nota;
    novo->sexo = sex;
    novo->prox = l;
    return novo;
}

void exibe_lista(Aluno* l)
{
    Aluno* p;
    for (p=l; p!=NULL; p=p->prox) 
        printf("mat: %d - nome: %s - nota: %.1f - sexo: %c\n", p->mat, p->nome, p->nota, p->sexo);
    printf("\n");
}

int conta_elementos_recursiva (Aluno* l)
{
    if (l!=NULL)
        return 1+conta_elementos_recursiva(l->prox);
    return 0;
}

int conta_sexo_recursiva (Aluno* l, char sexo)
{
    if (l!=NULL) {
        if (l->sexo==sexo)
            return 1+conta_sexo_recursiva(l->prox, sexo);
        else
            return conta_sexo_recursiva(l->prox, sexo);
    }
    return 0;
}

Aluno* quebraAoMeio (Aluno* l)
{
    Aluno* p = l, *ant = NULL;
    int i, f, n = conta_elementos_recursiva(l);
    if (n<2)
        return NULL;
    if (n%2==0)
        f = n/2;
    else
        f = (n/2)+1;
    for (i=0; i<f; i++) {
        ant = p;
        p = p->prox;
    }
    ant->prox=NULL; //fiz isso para parar de contar na metade
    return p;
}

int maiorMatricula (Aluno* l)
{
    Aluno* p = l;
    int  maiorMat = p->mat;
    for (p=p->prox; p!=NULL; p=p->prox)
        if (p->mat > maiorMat)
            maiorMat = p->mat;
    return maiorMat;
}

void lst_libera (Aluno* lst) 
{ 
  Aluno *p = lst, *t; 
  while (p != NULL) 
  { 
    t = p->prox; /* guarda referência p/ próx. Aluno */ 
    free(p); /* libera a memória apontada por p */ 
    p = t; /* faz p apontar para o próximo */ 
  } 
} 

int main (void) 
{ 
  Aluno *lal, *metade; 
  int nAlunos, nSexo, maiorMat;
  lal = lst_cria(); 
  lal = lst_insere(lal, 33, "Caio", 3.3, 'M'); 
  lal = lst_insere(lal, 11, "Ana", 1.1, 'F'); 
  lal = lst_insere(lal, 44, "Edu", 4.4, 'M'); 
  lal = lst_insere(lal, 66, "Luiz", 6.6, 'M'); 
  lal = lst_insere(lal, 22, "Bia", 2.2, 'F');  
  lal = lst_insere(lal, 55, "Jane", 5.5, 'F'); 
  lal = lst_insere(lal, 70, "Jorge", 6.0, 'M'); 
  /* inserir aqui a chamada para as suas funções e testes */ 
  exibe_lista(lal);
  nAlunos = conta_elementos_recursiva(lal);
  printf("Ha %d alunos na lista\n", nAlunos);
  nSexo = conta_sexo_recursiva(lal, 'F');
  printf("Ha %d alunos de sexo F na lista\n", nSexo);
  maiorMat = maiorMatricula(lal);
  printf("Maior matricula: %d\n", maiorMat);
  metade = quebraAoMeio(lal);
  printf("\nPrimeira metade da lista: \n");
  exibe_lista(lal);
  printf("Segunda metade da lista: \n");
  exibe_lista(metade);
  lst_libera(lal); 
  return 0; 
}

