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
