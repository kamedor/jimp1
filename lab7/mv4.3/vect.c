#include "vect.h"
#include <stdlib.h>

vect_t dodaj_do_wektora( vect_t k, int nowy){

  if (k == NULL){
    k = malloc( sizeof *k);
    k->l_wystapien=0;
    k->akt_pojemnosc=2;
    k->wystapienia = malloc(k->akt_pojemnosc *sizeof(*k->wystapienia));
  }


  if (k->akt_pojemnosc <= k->l_wystapien){
    k->akt_pojemnosc *=2;
    int *nwystapienia= realloc(k->wystapienia, k->akt_pojemnosc*sizeof(*k->wystapienia));
    k->wystapienia = nwystapienia;
  }

  k->wystapienia[k->l_wystapien]=nowy;
  k->l_wystapien++;
  return k;
}
