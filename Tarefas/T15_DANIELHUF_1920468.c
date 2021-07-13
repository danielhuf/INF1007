// T15 Programação II - Turma 33B
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

int buscaMatrRecurs (Aluno** vAlunos, int n, int matr)
{
    int s;
    if (n<=0)
        return -1;
    else {
        int meio = n/2;
        if (matr<vAlunos[meio]->matr)
            return buscaMatrRecurs (vAlunos, meio, matr);
        else if (matr>vAlunos[meio]->matr) {
            s = buscaMatrRecurs (&vAlunos[meio+1], n-1-meio, matr);
            if (s==-1)
                return -1;
            return (meio+1+s);
        }
        else
            return meio;
    }
}

void rotinaRecursiva (Aluno** vAlunos, int n, int matr)
{
    int i, cont=0, pos = buscaMatrRecurs(vAlunos, n, matr);
    if (pos==-1)
        printf("\nNao foi encontrado nenhum aluno com a matricula %d.\n", matr);
    else {
        printf("\nDados do aluno de matricula %d:\n", matr);
        printf("Nome: %s - Disciplina matriculada: %s - Nota final: %.1f", vAlunos[pos]->nome, vAlunos[pos]->codigo, vAlunos[pos]->nota);
        for (i=pos+1; i<n; i++)
            if (strcmp(vAlunos[i]->codigo,vAlunos[pos]->codigo)==0 && vAlunos[i]->nota<vAlunos[pos]->nota) {
                if (cont==0)
                    printf("\nDados dos alunos seguintes com nota menor e que tambem cursam %s:\n", vAlunos[pos]->codigo);
                printf("Nome: %s - Matricula: %d - Nota final: %.1f\n", vAlunos[i]->nome, vAlunos[i]->matr, vAlunos[i]->nota);
                cont++;
            }
        if (cont==0)
            printf("\nNao foi encontrado nenhum aluno seguinte com nota menor cursando %s.", vAlunos[pos]->codigo);
    }
}

int main()
{
    int i;
    Aluno* vAlunos[MAX]; 
    int totAlunos = le_arq_preenche(vAlunos);
    rotinaRecursiva(vAlunos, totAlunos, 266);
    rotinaRecursiva(vAlunos, totAlunos, 128);
    rotinaRecursiva(vAlunos, totAlunos, 413);
    for (i=0; i<totAlunos; i++)
        free(vAlunos[i]);
    return 0;
}