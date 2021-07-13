// T10 Programação II - Turma 33B
// Daniel Stulberg Huf - 1920468

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

FILE* openFile(const char* file, const char* mode)
{
    FILE *arq;
    arq = fopen(file, mode);
    if (arq==NULL)
        {printf("Erro ao abrir o arquivo.\n"); exit(1);}
    return arq;
}

char* criaVetor (char* nome)
{
    char* nomeCriado;
    int i, tam = strlen(nome);
    nomeCriado = (char*)malloc((tam+1)*sizeof(char));
    if (nomeCriado==NULL)
        {printf("Ha problema de alocacao de memoria.\n"); exit(2);}
    for (i=0; i<tam; i++)
        nomeCriado[i] = nome[i];
    return nomeCriado;
}

int le_arq_dados (char** vNomes)
{
    FILE *arq;
    char nomeLido[81];
    int nDados, lote, dia, mes, ano, maiorLote=0;
    vNomes[0]=NULL;
    arq = openFile("dadosDrone.txt", "r");
    while (!feof(arq)) {
        nDados = fscanf(arq, "%d%d%d%d %80[^\n]", &lote, &dia, &mes, &ano, nomeLido);
        if (nDados>=0 && nDados<5)
            {printf("Ha dados faltando.\n"); exit(3);}
        vNomes[lote] = criaVetor(nomeLido);
        if (lote>maiorLote)
            maiorLote = lote;
        printf("%1d %2d %2d %4d %s\n", lote, dia, mes, ano, vNomes[lote]);
    }
    fclose(arq);
    return maiorLote;
}

void atualiza_dados (char** vNomes, int n)
{
    char resposta[81], nome[81];
    int lote;
    printf("Quer corrigir nome? (sim, nao): ");
    scanf(" %[^\n]", resposta);
    while (strcmp(resposta, "sim")==0) {
        printf("Entre lote e nome: ");
        scanf("%d %80[^\n]", &lote, nome);
        if ((vNomes[lote]==NULL) || (lote>n))
            printf("O numero do lote nao esta correto.\n");
        else {
            vNomes[lote] = criaVetor(nome);
        }
        printf("Quer corrigir nome? (sim, nao): ");
        scanf(" %[^\n]", resposta);
    }
    printf("Arquivo gravado com sucesso!\n");
}

void gera_arquivo (char** vNomes, int n)
{
    FILE *arq;
    int i;
    arq = openFile("operadores.txt", "w");
    for (i=0; i<=n; i++) {
        if (vNomes[i]==NULL)
            fprintf(arq, "%d    unk\n", i);
        else
            fprintf(arq, "%d    %s\n", i, vNomes[i]);
    }
    fclose(arq);
}

int main()
{
    char** vNomes;
    int tot, i;
    vNomes = (char**)malloc(MAX*sizeof(char*));
    if (vNomes==NULL)
        printf("Ha problema de alocacao de memoria.\n");
    else {
        for (i=0; i<MAX; i++)
            vNomes[i] = NULL;
        tot = le_arq_dados(vNomes);
        atualiza_dados(vNomes, tot);
        gera_arquivo(vNomes, tot);
        for (i=0; i<tot; i++)
            if (vNomes[i]!=NULL)
                free(vNomes[i]);
        free(vNomes);
    }
    return 0;
}
