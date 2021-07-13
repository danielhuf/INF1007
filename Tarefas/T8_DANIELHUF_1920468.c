// T8 Programação II - Turma 33B
// Daniel Stulberg Huf - 1920468

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* converteNome(char *nome)
{
    int i, j, tam = strlen(nome);
    char *abrev = (char*)malloc((tam+1)*sizeof(char));
    if (abrev==NULL)
        return NULL;
    for (i=tam-1; i>=0 && nome[i] != ' '; i--);
    strcpy(abrev, &nome[i+1]);
    strcat(abrev, ", ");
    for (j=0; j<i; j++)
        if (nome[j]>='A' && nome[j]<='Z') {
            strncat(abrev, &nome[j], 1);
            strcat(abrev, ".");
        }
    return abrev;
}

char* normaAPA(char *nomeAutor, char *anoPub, char *titulo, char *editora)
{
    int tam;
    char *nomeAbrev, *autorAbrev = converteNome(nomeAutor);
    if (autorAbrev==NULL) 
        return NULL; 
    tam = strlen(autorAbrev) + strlen(anoPub) + strlen(titulo) + strlen(editora) + 9;
    nomeAbrev = (char*)malloc((tam)*sizeof(char));
    if (nomeAbrev==NULL)
        return NULL;
    strcpy(nomeAbrev, autorAbrev);
    free(autorAbrev);
    strcat(nomeAbrev, " (");
    strcat(nomeAbrev, anoPub);
    strcat(nomeAbrev, "). ");
    strcat(nomeAbrev, titulo);
    strcat(nomeAbrev, ". ");
    strcat(nomeAbrev, editora);
    strcat(nomeAbrev, ".");
    return nomeAbrev;
}


int main()
{
    int i;
    char *nomeFormat;
    char *nomes[5] = {"Maria Piedade Alves", "Stephen Hawking", "Milan Kundera", "Charles Duhigg", "Luis Fernando Verissimo"};
    char *publis[5] = {"2012", "1988", "1982", "2012", "2002"};
    char *titulos[5] = {"Metodologia Cientifica", "Uma Breve Historia do Tempo", "A insustentavel leveza do ser", "O Poder do Habito", "Banquete com os deuses"};
    char *editoras[5] = {"Escolar Editora", "Instrinseca", "Companhia das Letras", "Objetiva", "Objetiva"};
    for (i=0; i<5; i++)
    {
        nomeFormat = normaAPA(nomes[i], publis[i], titulos[i], editoras[i]);
        if (nomeFormat == NULL)
            printf("Houve erros de alocacao de memoria");
        else
            printf("%s\n", nomeFormat);
            free(nomeFormat);
    }
    return 0;
}











