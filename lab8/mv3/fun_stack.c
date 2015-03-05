#include "fun_stack.h"

#include <stdio.h>
#include <stdlib.h>


int top_of_funstack( void ){
  if( szczyt_stosu == NULL){
    fprintf(stderr, "Bład: Stos jest pusty\n");
    return EXIT_FAILURE;
  }
   return szczyt_stosu->par_level;
}

void put_on_fun_stack( int par_level, char *funame ){
  elem_t  *nowy= malloc(sizeof *nowy);
  nowy->par_level= par_level;
  nowy->funame= funame;
  if(szczyt_stosu == NULL)
		nowy->poprzednik= NULL;
  else
		nowy->poprzednik= szczyt_stosu;
	szczyt_stosu= nowy;
}

char *get_from_fun_stack( void ){
  if( szczyt_stosu == NULL){
    fprintf(stderr, "Bład: Stos jest pusty\n");
    return EXIT_FAILURE;
  }
  list_t zdejmowany = malloc(sizeof zdejmowany);
  zdejmowany = szczyt_stosu;
  szczyt_stosu = zdejmowany->poprzednik;
  
  return zdejmowany->funame;
  }