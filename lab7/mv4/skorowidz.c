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
	skorowidz->linie[i]= dodaj_do_wektora( skorowidz->linie[i], linia );
}

void wypisz_skorowidz( skorowidz_t *skorowidz ) {
  int i,j;

  for( i= 0; i < skorowidz->ile_slow; i++ ) {//pętla chodzi po słowach
    if( skorowidz->licznik[i]>0) { //jeśli znaleziono chociaż 1 wystąpienie
      vect_t tmp = skorowidz->linie[i];
      printf( "słowo \"%s\" wystąpiło w liniach:", skorowidz->slowa[i] );
      for(j=0;j < tmp->akt_elem; j++){
        printf( " %d", tmp->elem[j] );
	}
      printf( "\n" );
    } else {
      printf( "nie napotkano słowa \"%s\"\n", skorowidz->slowa[i] );
    }
  }
}

/*void wypisz_skorowidz( skorowidz_t *skorowidz ) {
  int i,j;

  for( i= 0; i < skorowidz->ile_slow; i++ ) {
    if( skorowidz->licznik[i] > 0 ) {
                        vect_t tmp= skorowidz->linie[i];
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
*/
