/******************************************************************************
NOME COMPLETO: Daniel Stulberg Huf
MATRICULA PUC-Rio: 1920468
DATA: 26/11/2020
DISCIPLINA: INF1007 TURMA: 33B
DECLARACAO DE AUTORIA:
 Declaro que este documento foi produzido em sua totalidade por mim,
 sem consultas a outros alunos, professores ou qualquer outra pessoa.
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct atleta
{
    char *nome;
    int altura;
    int peso;
} Atleta;

Atleta criaAtleta (char *nom, int alt, int pes)
{
    Atleta novoAtleta;
    novoAtleta.nome = (char*)malloc((strlen(nom)+1)*sizeof(char));
    if (novoAtleta.nome==NULL)
        exit(1);
    strcpy(novoAtleta.nome, nom);
    novoAtleta.altura = alt;
    novoAtleta.peso = pes;
    return novoAtleta;
}

Atleta* montaVetor ()
{
    Atleta* vDados = (Atleta*)malloc(8*sizeof(Atleta));
    if (vDados!=NULL) {
        vDados[0] = criaAtleta("daniel", 180, 70); 
        vDados[1] = criaAtleta("diego", 165, 60);
        vDados[2] = criaAtleta("diego", 172, 75);
        vDados[3] = criaAtleta("gabriela", 150, 42);
        vDados[4] = criaAtleta("gabriela", 150, 50);
        vDados[5] = criaAtleta("gabriela", 166, 80);
        vDados[6] = criaAtleta("marcos", 170, 90);
        vDados[7] = criaAtleta("tatiana", 158, 65);
    }
    return vDados;
}

void exibeVetor (Atleta* vDados, int n)
{
    int i;
    printf("VETOR DE ATLETAS:\n");
    for (i=0; i<n; i++)
        printf("%d: %5s %d %d\n", i, vDados[i].nome, vDados[i].altura, vDados[i].peso);
}

int compara (Atleta atleta, char* nom, int alt)
{
    int result = strcmp(nom, atleta.nome);
    if (result<0)
        return -1;
    else if(result>0)
        return 1;
    return alt-atleta.altura;
}

int buscaBinPos (Atleta* vDados, char* nom, int alt, int n)
{
    int valor, i, meio, ini=0, fim=n-1;
    while(ini<=fim) {
        meio = (ini+fim)/2;
        valor = compara(vDados[meio], nom, alt);
        if (valor<0)
            fim = meio-1;
        else if(valor>0)
            ini = meio+1;
        else {
            for (i=meio; i<n && strcmp(vDados[i].nome, nom)==0 && alt==vDados[i].altura; i++);
            return (i-1);
        }
    }
    if (valor>0) 
        return meio;
    else
        return (meio-1);
}

void testaPosicao (Atleta* vDados, char* nom, int alt, int pes, int n)
{
    int pos = buscaBinPos(vDados, nom, alt, n);
    printf("\nTESTE: ");
    if (pos==-1)
        printf("insere antes do inicio: %s %d %d - Inserir antes de 0", nom, alt, pes);
    else {
        if (pos==n-1)
            printf("insere apos o final: ");
        printf("%s %d %d - Inserir apos %d", nom, alt, pes, pos);
    }
}

int main()
{
    int i;
    Atleta* vDados = montaVetor();
    if (vDados!=NULL) {
        exibeVetor(vDados, 8);
        testaPosicao(vDados, "daniel", 172, 70, 8);     //antes de 0 com um nome ja existente
        testaPosicao(vDados, "amanda", 160, 52, 8);     //antes de 0 com um nome novo
        testaPosicao(vDados, "tatiana", 158, 66, 8);    //no final com um nome ja existente
        testaPosicao(vDados, "wanderley", 140, 45, 8);  //no final com um nome novo
        testaPosicao(vDados, "diego", 165, 54, 8);      //no meio com um nome ja existente e altura ja existente
        testaPosicao(vDados, "marcos", 160, 71, 8);     //no meio com um nome ja existente e altura nova
        testaPosicao(vDados, "gabriela", 157, 66, 8);   //no meio com um nome ja existente e altura entre duas alturas com nomes iguais
        testaPosicao(vDados, "leonardo", 190, 97, 8);   //no meio com um nome novo
        for (i=0; i<8; i++)
            free(vDados[i].nome);
        free(vDados);
    }
    return 0;
}