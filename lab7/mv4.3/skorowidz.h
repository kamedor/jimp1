#ifndef _SKOROWIDZ_H
#define _SKOROWIDZ_H

#include "vect.h"

typedef struct {
	int ile_slow;
	char **slowa;  
	int *licznik;   // w ilu liniach występują słowa
	vect_t *linie;  // listy zawierające nr linii zawierajacych
} skorowidz_t;
	
void zainicjuj_skorowidz( int argc, char **argv, skorowidz_t *s );

void dodaj_pozycje_skorowidza( skorowidz_t *skorowidz, int i, int linia );

int cmp(const void *a, const void *b);

void sortuj_skorowidz( skorowidz_t *skorowidz);

void wypisz_skorowidz( skorowidz_t *s );

#endif