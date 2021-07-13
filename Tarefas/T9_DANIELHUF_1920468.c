// T9 Programação II - Turma 33B
// Daniel Stulberg Huf - 1920468

#include <stdio.h>
#include <string.h>

void cifraCesar(char *cadeia, int chave)
{
    int soma;
    if (*(cadeia) != '\0')
    {
        if (*(cadeia)>='A' && *(cadeia)<='Z')
        {
            soma = ((*(cadeia)-'A') + chave)%26;
            *(cadeia)='A'+soma;
        }
        else if (*(cadeia)>='a' && *(cadeia)<='z')
        {
            soma = ((*(cadeia)-'a') + chave)%26;
            *(cadeia)='a'+soma;
        }
        cifraCesar((cadeia+1), chave);
    }
}

void cifraVigenere(char *cadeia, int n1, int n2)
{
    int soma;
    if (*(cadeia) != '\0')
    {
        if ((*(cadeia)>='A' && *(cadeia)<='Z') || (*(cadeia)>='a' && *(cadeia)<='z')) {
            if (*(cadeia)>='A' && *(cadeia)<='Z')
            {
                soma = ((*(cadeia)-'A') + n1)%26;
                *(cadeia)='A'+soma;
            }
            else if (*(cadeia)>='a' && *(cadeia)<='z')
            {
                soma = ((*(cadeia)-'a') + n1)%26;
                *(cadeia)='a'+soma;
            }
            cifraVigenere((cadeia+1), n2, n1);
        }
        else
            cifraVigenere((cadeia+1), n1, n2);
    }
}

int main()
{
    int i;
    //Irei criar duas copias de cada frase, pois assim posso codificar ambas as cifras de Cesar e Vigenere para uma mesma frase
    char copia1[101], copia2[101]; 
    char *frases[3]={"abcdefghijklmnopqrstuvwxyz", "O Rato Roeu a Roupa do Rei de Roma", "A vida e como andar de bicicleta. Para ter equilibrio voce tem que se manter em movimento."};
    for (i=0; i<3; i++) {
        printf("Frase original: %s", frases[i]);
        strcpy(copia1, frases[i]);
        strcpy(copia2, frases[i]);
        //No teste, defini a chave de Cesar como 10 e as chaves de Vigenere como 10 e 1
        cifraCesar(copia1, 10);
        cifraVigenere(copia2, 10, 1);
        printf("\nFrase na cifra de Cesar: %s", copia1);
        printf("\nFrase na cifra de Vigenere: %s\n\n", copia2);
    }
    return 0;
}






