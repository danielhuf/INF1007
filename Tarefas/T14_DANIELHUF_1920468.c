// T14 Programação II - Turma 33B
// Daniel Stulberg Huf - 1920468

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct aluno {
    int matr;
    char codigo[8];
    float nota;
    char nome[31];
} Aluno;

FILE* openFile(const char* file, const char* mode)
{
    FILE *arq;
    arq = fopen(file, mode);
    if (arq==NULL)
        {printf("Erro ao abrir o arquivo.\n"); exit(1);}
    return arq;
}

int le_arq_preenche (Aluno** vAlunos)
{
    FILE* arq;
    int nDado, nAlunos=0;
    arq = openFile("alunos.txt", "r");
    while (!feof(arq)) {
        vAlunos[nAlunos] = (Aluno*)malloc(sizeof(Aluno));
        if (vAlunos[nAlunos]==NULL)
            {printf("Houve problema de alocacao de memoria"); exit(2);}
        nDado = fscanf(arq, "%d %s%f %[^\n]", &vAlunos[nAlunos]->matr, vAlunos[nAlunos]->codigo, &vAlunos[nAlunos]->nota, vAlunos[nAlunos]->nome);
        nAlunos++;
    }
    fclose(arq);
    return nAlunos;
}

void buscaNotaInf (Aluno** vAlunos, int n)
{
    int i, cont=0;
    for (i=0; i<n; i++) {
        if (strncmp(vAlunos[i]->codigo,"INF",3)==0 && vAlunos[i]->nota>=7.0) {
            if (cont==0)
                printf("Matricula dos alunos de INF com notas maiores ou iguais a 7.0:  ");
            printf("%d ", vAlunos[i]->matr);
            cont++;
        }
    }
    if (cont==0)
        printf("Nao ha nenhum aluno de INF com nota maior ou igual a 7.0.");
}

int buscaMatr (Aluno** vAlunos, int n, int matr)
{
    int meio, ini=0, fim=n-1;
    while (ini<=fim) {
        meio = (ini+fim)/2;
        if (matr<vAlunos[meio]->matr)
            fim = meio-1;
        else if (matr>vAlunos[meio]->matr)
            ini = meio+1;
        else {
            return meio;
        }
    }
    return -1;
}

void rotinaDados (Aluno **vAlunos, int n, int matr)
{
    int pos = buscaMatr(vAlunos, n, matr);
    if (pos==-1)
        printf("\nNao foi encontrado nenhum aluno com a matricula %d.\n", matr);
    else {
        printf("\nDados do aluno de matricula %d:\n", matr);
        printf("Nome: %s - Disciplina matriculada: %s - Nota final: %.1f", vAlunos[pos]->nome, vAlunos[pos]->codigo, vAlunos[pos]->nota);
    }
}

int main()
{
    int i;
    Aluno* vAlunos[MAX];  
    int totAlunos = le_arq_preenche(vAlunos);
    buscaNotaInf(vAlunos, totAlunos);
    rotinaDados(vAlunos, totAlunos, 400);
    rotinaDados(vAlunos, totAlunos, 128);
    for (i=0; i<totAlunos; i++)
        free(vAlunos[i]);
    return 0;
}
