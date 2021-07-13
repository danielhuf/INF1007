/******************************************************************************
NOME COMPLETO: Daniel Stulberg Huf
MATRICULA PUC-Rio: 1920468
DATA: 29/10/2020
DISCIPLINA: INF1007 TURMA: 33B
DECLARACAO DE AUTORIA:
 Declaro que este documento foi produzido em sua totalidade por mim,
 sem consultas a outros alunos, professores ou qualquer outra pessoa.
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int retornaIntZonado(char *str)
{
    int n, soma, posicao = strlen(str)/2;
    if (*str != '\0') {
        n = *(str+1)-'0';
        soma = n * pow(10, posicao-1);
        return soma + retornaIntZonado(str+2);
    }
    return 0;
}

char* retornaStringZonada(int n, char *end)
{
    int casas, divi, num;
    char c;
    if (n != 0) {
        casas = 0;
        divi =1;
        while ((n/divi)!=0) {
            casas++;
            divi = divi*10;
        }
        num = n/(pow(10, casas-1));
        c = num + '0';
        *end++ = 'F';
        *end++ = c;
        *end = '\0';
        return retornaStringZonada(n%((int)(pow(10, casas-1))), end);
    }
    return end;
}

int main()
{
    int n1=5, n2=74993, n1Zonado, n2Zonado;
    char *cadeia1, *cadeia2;;
    cadeia1 = (char*)malloc(11*sizeof(char));
    cadeia2 = (char*)malloc(11*sizeof(char));
    if (cadeia1 == NULL)
        printf("Ha problema de alocacao de memoria");
    else if (cadeia2 == NULL)
        printf("Ha problema de alocacao de memoria");
    else {
        printf("Testando para n=%d: \n", n1);
        printf("Comprimento da string criada: %d\n", (int)(retornaStringZonada(n1, cadeia1)-cadeia1));
        printf("String correspondente no formato decimal zonado: %s\n", cadeia1);
        n1Zonado = retornaIntZonado(cadeia1);
        printf("Inteiro correspodente à string no formato decimal zonado: %d\n\n", n1Zonado);
        free(cadeia1);
        printf("Testando para n=%d: \n", n2);
        printf("Comprimento da string criada: %d\n", (int)(retornaStringZonada(n2, cadeia2)-cadeia2));
        printf("String correspondente no formato decimal zonado: %s\n", cadeia2);
        n2Zonado = retornaIntZonado(cadeia2);
        printf("Inteiro correspodente à string no formato decimal zonado: %d\n\n", n2Zonado);
        free(cadeia2);
    }
}
