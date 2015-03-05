#include "skorowidz.h"
#include <stdio.h>
#include <stdlib.h>

void zainicjuj_skorowidz( int argc, char **argv, skorowidz_t * skorowidz ) {
	int i;
	skorowidz->ile_slow= argc-2;
	skorowidz->slowa = malloc( skorowidz->ile_slow * sizeof * skorowidz->slowa );
	skorowidz->licznik = malloc( skorowidz->ile_slow * sizeof * skorowidz->licznik );
	skorowidz->linie = malloc( skorowidz->ile_slow * sizeof * skorowidz->linie );
  for( i= 2; i < argc; i++ ) {
    skorowidz->slowa[i-2]= argv[i];
    skorowidz->licznik[i-2]= 0;
		skorowidz->linie[i-2]= NULL;
  }
}

void dodaj_pozycje_skorowidza( skorowidz_t *skorowidz, int i, int linia ) {
	skorowidz->licznik[i]++;
	skorowidz->linie[i]= dodaj_do_listy( skorowidz->linie[i], linia );
}

void wypisz_skorowidz( skorowidz_t *skorowidz ) {
  int i,j;

  for( i= 0; i < skorowidz->ile_slow; i++ ) {
    if( skorowidz->licznik[i] > 0 ) {
			list_t tmp= skorowidz->linie[i];
      printf( "słowo \"%s\" wystąpiło w liniach:", skorowidz->slowa[i] );
      while( tmp != NULL ) {
        printf( " %d", tmp->nmbr );
				tmp= tmp->next;
			}
      printf( "\n" );
    } else {
      printf( "nie napotkano słowa \"%s\"\n", skorowidz->slowa[i] );
    }
  }
}
