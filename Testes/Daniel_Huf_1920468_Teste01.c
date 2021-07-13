/******************************************************************************
NOME COMPLETO: Daniel Stulberg Huf
MATRICULA PUC-Rio: 1920468
DATA: 22/10/2020
DISCIPLINA: INF1007 TURMA: 33B
DECLARACAO DE AUTORIA:
 Declaro que este documento foi produzido em sua totalidade por mim,
 sem consultas a outros alunos, professores ou qualquer outra pessoa.
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *copiaConteudo(char* destino, char *origem, int qtd)
{
    int i=0, j;
    while (*(destino+i) != '\0')
        i++;
    for (j=0; j<qtd; j++) {
        *(destino+i) = *(origem+j);
        i++;
    }
    *(destino+i) = '\0';
}

char* inverteString(char* sentenca, char c)
{
    int i, contador=0, tam=strlen(sentenca);
    char *stringInvertida = (char*)malloc((tam+1)*sizeof(char));
    if (stringInvertida==NULL)
        return NULL;
    for (i=tam-1; i>=0; i--) {
        if (*(sentenca+i) == c) {
            copiaConteudo(stringInvertida, sentenca+i+1, contador);
            copiaConteudo(stringInvertida, sentenca+i, 1);
            contador=0;
        }
        else
            contador++;
    }
    copiaConteudo(stringInvertida, sentenca, contador);
    return stringInvertida;
}

int main()
{
    int i;
    char c, sentenca[81], *invertida;
    for (i=0; i<3; i++)
    {
        printf("Forneca o caractere que delimita as palavras: ");
        c = getc(stdin);
        printf("Forneca a sentenca a ser invertida: ");
        scanf(" %80[^\n]", sentenca);
        printf("Sentenca original: %s\n", sentenca);
        invertida = inverteString(sentenca, c);
        if (invertida==NULL)
            printf("Houve erro de alocacao de memoria ao criar a sentenca invertida.\n");
        else {
            printf("Sentenca invertida: %s\n\n", invertida);
            free(invertida);
        }
        c = getc(stdin);
    }
    return 0;
}






