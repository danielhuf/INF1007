/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* inverte_letra(char* str)
{
    int i, tam=strlen(str);
    char* stringTrocada;
    stringTrocada = (char*)malloc((tam+1)*sizeof(char));
    if (stringTrocada == NULL)
        return NULL;
    for (i=0; str[i]!='\0'; i++)
    {
        if (str[i]>='a' && str[i]<='z')
            stringTrocada[i] = (str[i]-'a') + 'A';
        else if (str[i]>='A' && str[i]<='Z')
            stringTrocada[i] = (str[i]-'A') + 'a';
        else
            stringTrocada[i] = str[i];
    }
    stringTrocada[i] = '\0';
    return stringTrocada;
}

char** inverte_letraVet(char** vet, int dim)
{
    int i;
    char* vInv;
    char** vetorInvertido;
    vetorInvertido = (char**)malloc(dim*sizeof(char*));
    if (vetorInvertido == NULL)
        return NULL;
    for (i=0; i<dim; i++)
    {
        if (vet[i] != NULL) {
            vInv = inverte_letra(vet[i]);
            vetorInvertido[i] = vInv;
        }
        else
            vetorInvertido[i] = NULL;
    }
    return vetorInvertido;
}

int main()
{
    int i;
    char *vet[10] = {"PUC-Rio", NULL, NULL, "Sao Paulo", "gusrda-chuva", "NAC Dance", NULL, "MUDANCAS & Transportes"};
    char **vInv;
    vInv = inverte_letraVet(vet, 8);
    if (vInv==NULL)
        printf("Falta espaço na memoria");
    else
    {
        for (i=0; i<8; i++)
            if (vInv[i]!=NULL) {
                printf("%s\n", vInv[i]);
                free(vInv[i]);
            }
        free(vInv);
    }
    return 0;
}

