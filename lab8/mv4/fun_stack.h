#ifndef _FUN_STACK_H_IS_INCLUDED_
#define _FUN_STACK_H_IS_INCLUDED_
#include <stdlib.h>
typedef struct e {
  int par_level;
  char *funame;
  struct elem_t  *poprzednik;        
} *list_t, elem_t;

list_t szczyt_stosu;

int top_of_funstack( void );  // zwraca par_level - "zagłębienie nawiasowe" przechowywane na szczycie
void put_on_fun_stack( int par_level, char *funame ); // odkłada na stos parę (funame,par_level)
char *get_from_fun_stack( void ); // usuwa z wierzchołka parę (funame,par_level), zwraca zdjętą funame

#endif

