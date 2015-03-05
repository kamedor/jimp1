#include "wyszukaj.h"

#include <string.h>
#include <stdio.h>
#include <ctype.h>

void wyszukaj(FILE *fin, skorowidz_t *skorowidz){
  int i; //zmienna indeksująca
  char buf[BUFSIZE];
  int nr_linii=0;
  char *p,*k;
  while( fgets( buf, BUFSIZE, fin ) != NULL ) {//while chodzące po liniach pliku (tylko raz cały plik)
    nr_linii++;                               //nr aktualnej linii
    for( i= 0; i < skorowidz->ile_slow; i++ )  //sprawdza wszystkiej słowa w aktualnej linii
      if( (p= strstr( buf, skorowidz->slowa[i] )) != NULL ) {     //porównuje ite-słowo z aktualną linią
       p= p - 1; //sprawdzać będę znak przed znalezionym słowem
       k= p + 1 + strlen(skorowidz->slowa[i]);      //i znak po znalezionym slowie
       if ((isalnum(*p)==0) && (isalnum(*k)==0) )
        dodaj_pozycje_skorowidza( skorowidz, i, nr_linii );  //dodaje nr akt_linii do skorowidza
      }
  }
}
