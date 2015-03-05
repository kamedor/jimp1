#ifndef _SKOROWIDZ_H
#define _SKOROWIDZ_H

#include "list.h"

typedef struct {
	int ile_slow;
	char **slowa;  
	int *licznik;   // w ilu liniach występują słowa
	list_t *linie;  // listy zawierające nr linii zawierajacych
} skorowidz_t;
	
void zainicjuj_skorowidz( int argc, char **argv, skorowidz_t *s );

void dodaj_pozycje_skorowidza( skorowidz_t *skorowidz, int i, int linia );

void wypisz_skorowidz( skorowidz_t *s );

#endif
