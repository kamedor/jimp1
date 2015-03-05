#include "vect.h"

#include <stdio.h>

vect_t
dodaj_do_wektora (vect_t l, int n)
{
  if (l == NULL)
    { // w mojej wersji w calym ifie zamiast nwc bylo l
      l = malloc (sizeof *l); //w mojej wersji vect_t l = malloc...
      l->akt_elem = 0;
      l->max_elem = 2;
      l->elem= (int*)malloc(l->max_elem * sizeof(int*));
    }
  if (l->akt_elem >= l->max_elem)
    {
      int *tmp;
      l->max_elem *=2;
      tmp = (int*)realloc(l->elem, l->max_elem*sizeof(int*));
      l->elem = tmp;
    }
  l->elem[(l->akt_elem)] = n;
  l->akt_elem++;
  printf("l->elem[l->akt_elem]=%d l->akt_elem=%d n=%d\n", l->elem[l->akt_elem],l->akt_elem,n);
  return l;
}
/*
#include "list.h"

#include <stdlib.h>

list_t dodaj_do_listy( list_t l, int n ) {
  // dopisuje nowy element na koniec listy l
  // nowy element przechowuje n (jego nmbr == n)
        if( l == NULL ) {
                list_t nw= malloc( sizeof *nw );
                nw->nmbr= n;
                nw->next= NULL;
                return nw;
        } else {
                list_t tmp= l;
                while( tmp->next != NULL )
                        tmp= tmp->next;
                tmp->next= malloc( sizeof * (tmp->next) );
                tmp->next->nmbr= n;
                tmp->next->next= NULL;
                return l;
        }
}
*/
