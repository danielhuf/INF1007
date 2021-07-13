/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void substituiCaractere(char *cadeia, char c)
{
    if (cadeia[0] != '\0')
    {
        if (cadeia[0] == c)
            cadeia[0] = '*';
        substituiCaractere(&cadeia[1], c); //ou (cadeia+1, c)
    }
}

int main()
{
    char s[]="Batata";
    substituiCaractere(s, 'a');
    printf("%s", s);
}

