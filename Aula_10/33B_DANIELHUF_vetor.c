/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int* vetorIntercalado(int *v1, int *v2, int n1, int n2)
{
    int *v3, i, maior, menor, j;
    v3 = (int*)malloc((n1+n2)*sizeof(int));
    if (v3 == NULL)
        return NULL;
    if (n1>n2) {
        maior = n1;
        menor = n2;
    }
    else {
        maior = n2;
        menor = n1;
    }
    for (i=0; i<menor; i++) 
    {
        v3[2*i] = v1[i];
        v3[(2*i)+1] = v2[i];
    }
    j=2*i;
    if (n1<n2)
        for (i=menor; i<maior; i++)
            v3[(j++)] = v2[i];
    else
        for (i=menor; i<maior; i++)
            v3[(j++)] = v1[i];
    return v3;
}

int main()
{
    int v1[4]={1,3,5,7}, v2[6]={2,4,6,8,10,12};
    int *v3, i;
    v3 = vetorIntercalado(v1,v2,4,6);
    if (v3!=NULL)
    {
        for (i=0; i<10; i++)
            printf("%d - ", v3[i]);
        free(v3);  
    }
    return 0;
}
