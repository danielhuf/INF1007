/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct candidato {	
    int	inscricao;
	char nome[51];
	int	idade;
	float nota;
};
typedef struct candidato Candidato;

Candidato* criaCandidato (int insc, char* nome, int idade, float nota)
{
    Candidato* cand;
    cand = (Candidato*)malloc(sizeof(Candidato));
    if (cand==NULL)
        return NULL;
    cand->inscricao = insc;
    strcpy(cand->nome,nome);
    cand->idade = idade;
    cand->nota = nota;
    return cand;
}

void exibeTodosCandidatos (Candidato** vCand, int n)
{
    int i;
    printf("Dados dos candidatos\n");
    for (i=0; i<n; i++) {
        printf("Inscricao: %d - ", vCand[i]->inscricao);
        printf("Nome: %s - ", vCand[i]->nome);
        printf("Idade: %d - ", vCand[i]->idade);
        printf("Nota: %.1f\n", vCand[i]->nota);
    }
}

Candidato* buscaInscricao (Candidato** vCand, int n, int insc)
{
    int i;
    for (i=0; i<n; i++) 
        if ((vCand[i]->inscricao)==insc)
            return vCand[i];
    return NULL;
}

int main()
{
	Candidato *vpcandidato[8];
	int i, insc;
	Candidato *pont;
	vpcandidato[0]= criaCandidato(444,"Luiz",34, 7.8f);
	vpcandidato[1]= criaCandidato(111,"Rita",56, 8.8f);
	vpcandidato[2]= criaCandidato(999,"Rute",32, 7.1f);
	vpcandidato[3]= criaCandidato(555,"Dina",27, 6.4f);
	vpcandidato[4]= criaCandidato(777,"Lana",35, 5.3f);
	vpcandidato[5]= criaCandidato(666,"Tais",29, 9.8f);
	vpcandidato[6]= criaCandidato(222,"Cris",31, 7.2f);
	vpcandidato[7]= criaCandidato(333,"Vera",44, 5.4f);

	exibeTodosCandidatos(vpcandidato, 8);
	printf("Forneca uma inscricao: ");
	scanf("%d", &insc);
	pont = buscaInscricao(vpcandidato, 8, insc);
	if (pont == NULL)
	    printf("Nenhum candidato com essa inscricao.\n");
	else
	    printf("Candidato com essa inscricao: %s", pont->nome);
	for (i=0; i<8; i++)
	    free(vpcandidato[i]);
    return 0;
}

