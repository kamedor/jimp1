#ifndef _ALEX_H_IS_INCLUDED_
#define _ALEX_H_IS_INCLUDED_

#include <stdio.h>//rozpoznanie FILE

typedef enum { ERROR, OTHER,    EOFILE, OPEBRA, CLOBRA, IDENT, OPEPAR, CLOPAR } lexem_t;
//            błąd, inny symbol EOF     {         }     identyfikator (   )
// typy lexem

void    alex_init4file( FILE *);  //zacznij czytać plik
lexem_t alex_nextLexem(void);     //dodaj lexem w czyt_pliku
char*   alex_ident(void);         //daj ostatni identyfikator (?)
int     alex_getLN();             //daj akt_nr_linii

#endif
