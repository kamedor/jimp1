#include <stdio.h>  // wiadomo po co
#include <stdlib.h>
#include <string.h> // strstr

#include "list.h"
#include "skorowidz.h"

#define BUFSIZE 8192   // zakładamy, że linie będą krótsze niż 8kB

int
main( int argc, char **argv ) {
  int i;
  int nr_linii;
  char buf[BUFSIZE];

  FILE *in= argc > 1 ? fopen( argv[1], "r" ) : stdin;

	skorowidz_t skorowidz;

  zainicjuj_skorowidz( argc, argv, &skorowidz);

  if( skorowidz.ile_slow == 0 ) {
    fprintf( stderr, "%s: błąd: proszę podać słowa do wyszukiwania\n", argv[0] );
    return EXIT_FAILURE;
  }

  if( in == NULL ) {
    fprintf( stderr, "%s: błąd: nie mogę czytać pliku %s\n", argv[0], argv[1] );
    return EXIT_FAILURE;
  }

  nr_linii= 0;
  while( fgets( buf, BUFSIZE, in ) != NULL ) {
    nr_linii++;
    for( i= 0; i < skorowidz.ile_slow; i++ )
      if( strstr( buf, skorowidz.slowa[i] ) != NULL ) {
				dodaj_pozycje_skorowidza( &skorowidz, i, nr_linii );
      }
  }

  wypisz_skorowidz( &skorowidz );

  return EXIT_SUCCESS;
}
