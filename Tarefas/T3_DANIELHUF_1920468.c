// T3 Programação II - Turma 33B
// Daniel Stulberg Huf - 1920468

#include <stdio.h>

int crianumero (int n1, int n2)
{
    return n1*100 + n2;
}

int main()
{
    int usu, contador;
    printf ("Digite total de usuarios: ");
    scanf ("%d", &usu);
    for (contador = 0; contador < usu; contador++) {
        int dia, mes, ano, senha;
        printf ("\nForneca sua data de nascimento como 3 valores inteiros:\n");
        scanf ("%d%d%d", &dia, &mes, &ano);
        senha = crianumero(dia, mes) + crianumero(mes, dia) + ano;
        printf ("senha: %d\n", senha);
    }
    return 0;
}



