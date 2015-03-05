#include "skorowidz.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void zainicjuj_skorowidz( int argc, char **argv, skorowidz_t * skorowidz ) {
  int i;

  if( argc<3 ){
    fprintf(stderr, "%s: błąd: proszę podać słowa do wyszukiwania\n", argv[0] );
    exit(EXIT_FAILURE);
  }
  else{
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
}

void dodaj_pozycje_skorowidza( skorowidz_t *skorowidz, int i, int linia ) {
  skorowidz->licznik[i]++;//które to wystąpienie danego słowa
  skorowidz->linie[i]= dodaj_do_wektora( skorowidz->linie[i], linia );
}

int cmp(const void *a, const void *b) {
  char *sa= *(char**)a;
  char *sb= *(char**)b;
  return strcmp(sa,sb);
}

void sortuj_skorowidz( skorowidz_t *skorowidz){
  qsort( skorowidz->slowa, skorowidz->ile_slow,sizeof(char*),cmp);
}

void wypisz_skorowidz( skorowidz_t *skorowidz) {
  int i,j;
  for( i= 0; i< skorowidz->ile_slow; i++) { //zmienna przechodzi po kolei po wszystkich słowach
    if ( skorowidz->licznik[i] > 0 ) {
      printf( "słowo \"%s\" wystąpiło w liniach:", skorowidz->slowa[i] );
      for(j=0; j < skorowidz->linie[i]->l_wystapien ; j++)
        printf( " %d", skorowidz->linie[i]->wystapienia[j]);
      printf( "\n");
    } else {
      printf( "nie napotkano słowa \"%s\"\n", skorowidz->slowa[i] );
    }
  }
}
