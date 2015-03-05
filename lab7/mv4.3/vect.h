#ifndef _VECT_H
#define _VECT_H

typedef struct {
  int *wystapienia;
  int l_wystapien;
  int akt_pojemnosc;
} * vect_t;

vect_t dodaj_do_wektora( vect_t k, int nowy);
#endif
