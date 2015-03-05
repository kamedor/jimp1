#ifndef _ALEX_H_IS_INCLUDED_
#define _ALEX_H_IS_INCLUDED_

#include <stdio.h>

#define BUFSIZE 50
// interesujące leksemy: błąd, inny symbol, koniec pliku, otwierająca klamra {, 
//                       zamykająca klamra }, identyfikator, otwierający nawias, 
//                       zamykający nawias
typedef enum { ERROR, OTHER, EOFILE, OPEBRA, CLOBRA, IDENT, OPEPAR, CLOPAR } lexem_t;
static char **keyword=NULL;


int isKeyworda(char *ident);
void    alex_init4file( FILE * );  // zacznij czytać nowy plik
lexem_t alex_nextLexem( void );    // daj kolejny leksem w czytanym pliku
char *  alex_ident( void );        // daj ostatni identyfikator
int     alex_getLN();              // daj aktualny nr linii

#endif

