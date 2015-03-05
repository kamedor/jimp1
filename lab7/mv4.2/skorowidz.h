#ifndef _SKOROWIDZ_H
#define _SKOROWIDZ_H

#include "vect.h"
//#include "list.h"

typedef struct {
	int ile_slow;   //ilość wszystkich słów np.2
	char **slowa;   //"Ala" "kota"
	int *licznik;   // w ilu liniach występują słowa np.licznik[0]=2 licznik[1]=1
	vect_t *linie;  //co to za linie np. linie[0]->elem[0]=1 linie[0]->elem[1]=3
	//list_t *linie;  // listy zawierające nr linii zawierajacych
} skorowidz_t;
	
void zainicjuj_skorowidz( int argc, char **argv, skorowidz_t *s );

void dodaj_pozycje_skorowidza( skorowidz_t *skorowidz, int i, int linia );

void wypisz_skorowidz( skorowidz_t *s );

#endif
