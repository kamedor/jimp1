#include <stdio.h>
#include <stdlib.h>
#include "alex.h"

int main(int argc, char **argv){
	 int npar, nbra = 0;
	 FILE *in = fopen (argv[1], "r");
	 alex_init4file (in);
	 lexem_t lex;
	 lex = alex_nextLexem ();
		while (lex != EOFILE) {
			switch (lex) {
				case OPEBRA:
					printf("OPEBRA\n");
					break;
				case OPEPAR:
					printf("OPEPAR\n");
					break;
				case CLOPAR:
					printf("CLOPAR\n");
					break;
				case CLOBRA:
					printf("CLOBRA\n");
					break;
				case IDENT:{
        char *iname = alex_ident ();   // zapamiętaj identyfikator i patrz co dalej
        lexem_t nlex = alex_nextLexem ();
        if (nlex == OPEPAR) {   // nawias otwierający - to zapewne funkcja
          npar++;
          put_on_fun_stack (npar, iname);       // odłóż na stos funkcji
                                                // stos f. jest niezbędny, aby poprawnie obsłużyć sytuacje typu
                                                // f1( 5, f2( a ), f3( b ) )
        }
        else {                  // nie nawias, czyli nie funkcja
          lex = nlex;
          continue;
        }
      }
      break;
			}
		lex = alex_nextLexem ();
		}
	return 0;
}