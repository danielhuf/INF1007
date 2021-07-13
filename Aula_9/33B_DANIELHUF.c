/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define TOT 3

void exibeMenoresUltimo(int *vVal, int tot)
{
    int i;
    int ultimo = vVal[tot-1];
    printf("Valores menores que o ultimo valor fornecido: \n");
    for (i=0; i<tot; i++) {
        if (*(vVal+i) < ultimo)
            printf("%d\n", *(vVal+i));
    }
}

float calculaMedia(int *vVal, int tot)
{
    int i;
    int somaValores = 0;
    float med;
    float media;
    for (i=0; i<tot; i++){
        somaValores += *(vVal+i);
    }
    med = (float)somaValores/tot;
    return med;
}

int busca1(int *vVal, int tot, int x)
{
    int i;
    for (i=0; i<tot; i++) {
        if (x == *(vVal+i))
            return 1;
    }
    return 0;
}

int busca2(int *vVal, int tot, int x)
{
    int i;
    for (i=0; i<tot; i++) {
        if (x == *(vVal+i))
            return i;
    }
    return -1;
}

int verificaOrd(int *vVal, int tot)
{
    int i;
    for (i=1; i<tot; i++)
        if (*(vVal+i) < vVal[i-1])
        return 0;
    return 1;
}

void Inverte(int *vVal, int tot, int *vInv)
{
    int i;
    for (i=0; i<tot; i++)
        vInv[tot-(i+1)] = vVal[i];
}

int main()
{
    int vValores[TOT], i, val, bool, pos, verif, vInversos[TOT];
    float media;
    for (i=0; i<TOT; i++) {
        printf("Forneca um valor inteiro: ");
        scanf("%d", vValores+i);
    }
    exibeMenoresUltimo(vValores, TOT);
    media = calculaMedia(vValores, TOT);
    printf("Media dos valores obtidos: %.1f", media);
    printf("\nForneca um valor que deseja buscar: ");
    scanf("%d", &val);
    bool = busca1(vValores, TOT, val);
    if (!bool){
        printf("Valor nao encontrado. \n");
    }
    else {
        printf("Valor encontrado. \n");
    }
    pos = busca2(vValores, TOT, val);
    if (pos != -1){
        printf("Posicao: %d.\n", pos); 
    }
    verif = verificaOrd(vValores, TOT);
    if (!verif){
        printf("Elementos nao estao ordenados.\n");
    }
    else{
        printf("Elementos estao ordenados. \n");
    }
    Inverte(vValores, TOT, vInversos);
    for (i=0; i<TOT; i++)
        printf("%d\n", vInversos[i]);
    return 0;
}

