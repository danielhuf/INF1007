/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* ultimoNome(char *cadeia)
{
    int i, tam = strlen(cadeia);
    for (i = tam-1; i>=0 && cadeia[i]!=' '; i--);
    return (cadeia + i + 1 );   //ou return &cadeia[i+1]
}

char* criaNome(char *nomeBebe, char *nomeMae, char *nomePai)
{
    char *sobrenomeMae = ultimoNome(nomeMae);
    char *sobrenomePai = ultimoNome(nomePai);
    int tam = strlen(nomeBebe)+strlen(sobrenomeMae)+strlen(sobrenomePai)+3;
    char *nome = (char*)malloc((tam)*sizeof(char));
    if (nome==NULL)
        return NULL;
    strcpy(nome, nomeBebe);
    strcat(nome, " ");
    strcat(nome, sobrenomeMae);
    strcat(nome, " ");
    strcat(nome, sobrenomePai);
    return nome;
}

int main()
{
    char mae[] = "Ana Luiza Resende", pai[] = "Rui Alberto Medeiros", bebe[] = "Pedro";
    char *nomeBebe;
    nomeBebe = criaNome(bebe, mae, pai);
    if (nomeBebe == NULL)
        {printf("Houve erros de alocacao de memoria"); exit(1);}
    printf("Nome do bebe: %s\n", nomeBebe);
    free(nomeBebe);
    return 0;
}

