#ifndef _VECT_H_
#define _VECT_H_

typedef struct e {
        int akt_elem;
        int max_elem;
        int *elem;
} * vect_t;

vect_t dodaj_do_wektora( vect_t l, int n );

#endif
/*
#ifndef _LIST_H_
#define _LIST_H_

typedef struct e {
        int nmbr;
        struct e *next;
} * list_t;

list_t dodaj_do_listy( list_t l, int n );

#endif
*/