#ifndef _LIST_H_
#define _LIST_H_

typedef struct e {
	int nmbr;
	struct e *next;
} * list_t;

list_t dodaj_do_listy( list_t l, int n );

#endif
