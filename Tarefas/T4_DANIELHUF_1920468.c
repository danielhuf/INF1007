// T4 Programação II - Turma 33B
// Daniel Stulberg Huf - 1920468

#include <stdio.h>
#define IN 1
#define OUT 0

void estatistica(int pal, int sent) {
	printf("\tEstatistica. Palavras: %d Sentencas: %d", pal, sent);
	if (pal != 0)
		printf(" Media: %.1f",(float)pal/sent);
	printf("\n");
}

int main(void) {
	int palavras = 0;
	int sentencas = 0;
	int state = OUT;
	char c;
	c = getc(stdin);
	while (c != '@') {
		if (c == '#') {
			estatistica(palavras, sentencas);
			palavras = 0;
			sentencas = 0;
		}
		else if (c == '.' || c == '?') {
			sentencas++;
		}
		else if (state && (c == ' ' || c == '\n' || c == '\t')) {
			state = OUT;
		}
		else if (!state && c != ' ' && c != '\n' && c != '\t') {
			palavras++;
			state = IN;
		}
		c = getc(stdin);
	}
	printf("Leitura interrompida pelo usuario");
	return 0;
}






