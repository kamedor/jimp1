#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "skorowidz.h"
#include "plik.h"
#include "wyszukaj.h"

int main(int argc, char **argv) {
  FILE *in= wczytaj_plik(argc,argv);

  skorowidz_t skorowidz;
  
  zainicjuj_skorowidz( argc, argv, &skorowidz);

  wyszukaj(in, &skorowidz);

  sortuj_skorowidz( &skorowidz );

  wypisz_skorowidz( &skorowidz );

  return EXIT_SUCCESS;
}
