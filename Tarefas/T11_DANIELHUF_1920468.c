// T11 Programação II - Turma 33B
// Daniel Stulberg Huf - 1920468

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUM 7

FILE* openFile(const char* file, const char* mode)
{
    FILE *arq;
    arq = fopen(file, mode);
    if (arq==NULL)
        {printf("Erro ao abrir o arquivo.\n"); exit(1);}
    return arq;
}

void trocaBrancos (char* str)
{
    int i, tam=strlen(str);
    for (i=0; i<tam; i++) 
        if (str[i]==' ')
            str[i] = '_';
}

void le_arq_dados (int* vValores, char* nome)
{
    FILE* arq;
    int nDados, valor, i;
    char c;
    arq = openFile("dadosDrone2.txt", "r");
    while (!feof(arq)) {
        nDados = fscanf(arq, " %80[^:]", nome);
        printf("%s: ", nome);
        nDados += fscanf(arq, "%c", &c);
        for (i=0; i<NUM; i++) {
            nDados += fscanf(arq, "%d", &valor);
            vValores[i]  = valor;
            printf("%d ", vValores[i]);
        }
    }
    fclose(arq);
}

void grava_arquivo (int *vValores, char* nome)
{
    FILE* arq;
    char nomeArquivo[81];
    strcpy(nomeArquivo, "stream_");
    trocaBrancos(nome);
    strcat(nomeArquivo, nome);
    strcat(nomeArquivo, ".dat");
    arq = openFile(nomeArquivo, "wb");
    fwrite(vValores, sizeof(int), NUM, arq);
    fclose(arq);
    printf("\nArquivo gravado com sucesso!");
    strcpy(nome, nomeArquivo);
}

int maiorValor (int* vValores, int n)
{
    int i, maiorValor = vValores[0];
    for (i=1; i<n; i++) {
        if (vValores[i]>maiorValor)
            maiorValor = vValores[i];
    }
    return maiorValor;
}

void le_arq_gerado (char* nome, int n)
{
    FILE* arq;
    int maior, valoresBin[NUM];
    arq = openFile(nome, "rb");
    fread(valoresBin, sizeof(int), NUM, arq);
    maior = maiorValor(valoresBin, NUM);
    printf("\nMax: %d", maior);
    fclose(arq);
}

int main()
{
    int vValores[NUM];
    char nome[81];
    le_arq_dados(vValores, nome);
    grava_arquivo(vValores, nome);
    le_arq_gerado(nome, NUM);
    return 0;
}
