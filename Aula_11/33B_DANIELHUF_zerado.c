/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int* criaVetorDeProdutosZerados(int *vetCod, int *vetEstoq, int nProd, int *nZerados)
{
    int i, *vetZerados, pos;
    *nZerados=0;
    for (i=0; i<nProd; i++) 
        if (vetEstoq[i]==0)
            (*nZerados)++;   //devemos colocar entre parenteses no ponteiro!!
    if ((*nZerados)==0)
        return NULL;
    vetZerados = (int*)malloc((*nZerados)*sizeof(int));
    if (vetZerados==NULL)
        return NULL;
    pos = 0;
    for (i=0; i<nProd; i++) 
        if (vetEstoq[i]==0) 
            vetZerados[pos++]=vetCod[i];
    return vetZerados;
}

int main()
{
    int *vetZerados, nZerados, i;
    int vetCod[]={122,126,474,473,293,583,382,483,294,694};
    int vetEstoq[]={2,7,0,4,6,0,0,1,6,3};
    vetZerados = criaVetorDeProdutosZerados(vetCod, vetEstoq, 10, &nZerados);
    if (vetZerados!=NULL) {
        printf("\nCodigo dos produtos zerados: ");
        for (i=0; i<nZerados; i++)
            printf("%d  ", vetZerados[i]);
        free(vetZerados);
    }
    else if (nZerados==0)
        printf("Ha ha produtos zerados no estoque\n");
    else
        printf("Nao ha espaco na memoria\n");
    return 0;
}


