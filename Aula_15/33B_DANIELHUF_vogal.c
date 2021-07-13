/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int ehVogal(char c)
{
    if (c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
        return 1;
    return 0;
}

void vogais(char *cadeia)
{
    if (cadeia[0] != '\0')
    {
        vogais(&cadeia[1]);
        if (ehVogal(cadeia[0]))
            printf("%c", cadeia[0]);
    }
}

int main()
{
    vogais("SEXTA TEM FESTA VIP!");
    return 0;
}
