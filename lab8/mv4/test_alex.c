#include "alex.h"

#include <stdio.h>
int czytaj_nawiasy_eof(FILE *dane){
	alex_init4file (dane);
	lexem_t lex;
	lex= alex_nextLexem();
	while(lex !=EOFILE){
		switch(lex){
			case OPEPAR:
				printf("OPEPAR\n");
				break;
			case CLOPAR:
				printf("CLOPAR\n");
				break;
			case OPEBRA:
				printf("OPEBRA\n");
				break;
			case CLOBRA:
				printf("CLOBRA\n");
				break;
			case IDENT:
				printf("IDENT\n");
				break;
			case OTHER:
				printf("OTHER\n");
				break;
			case EOFILE:
				printf("EOFILE\n");
				break;
			case ERROR:
				printf("ERROR\n");
				break;
			}
			lex= alex_nextLexem();
	}
	return 0;
}


int main(int argc, char **argv) {
	FILE *plik= fopen(argv[1] , "r");
	if (plik ==NULL) {
		fprintf(stderr, "B³¹d g³upcze\n");
		return -1;
	}
	// Funkcja sprawdza dzia³anie dla nawiasów i eof - DZIA£A!!!
	czytaj_nawiasy_eof(plik);
	//czytaj_napisy_error();
	return 0;
}