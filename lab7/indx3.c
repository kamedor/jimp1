#include <stdio.h>  // wiadomo po co
#include <stdlib.h> 
#include <string.h> // strstr

#define BUFSIZE 8192   // zakładamy, że linie będą krótsze niż 8kB

typedef struct e {
	int nmbr;
	struct e *next;
} * list_t;

list_t dodaj_do_listy( list_t l, int n ) {
  // dopisuje nowy element na koniec listy l
  // nowy element przechowuje n (jego nmbr == n)
	if( l == NULL ) {
		list_t nw= malloc( sizeof *nw );
		nw->nmbr= n;
		nw->next= NULL;
		return nw;
	} else {
		list_t tmp= l;
		while( tmp->next != NULL )
			tmp= tmp->next;
		tmp->next= malloc( sizeof * (tmp->next) );
		tmp->next->nmbr= n;
		tmp->next->next= NULL;
		return l;
	}
}

typedef struct {
	int ile_slow;
	char **slowa;  
	int *licznik;   // w ilu liniach występują słowa
	list_t *linie;  // listy zawierające nr linii zawierajacych
} skorowidz_t;
	
void zainicjuj_skorowidz( int argc, char **argv, skorowidz_t *s );

void dodaj_pozycje_skorowidza( skorowidz_t *skorowidz, int i, int linia );

void wypisz_skorowidz( skorowidz_t *s );

int
main( int argc, char **argv ) {
  int i;
  int ile_linii;
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

  ile_linii= 0;
  while( fgets( buf, BUFSIZE, in ) != NULL ) {
    ile_linii++;
    for( i= 0; i < skorowidz.ile_slow; i++ )
      if( strstr( buf, skorowidz.slowa[i] ) != NULL ) {
				dodaj_pozycje_skorowidza( &skorowidz, i, ile_linii );
      }
  }

  wypisz_skorowidz( &skorowidz );

  return EXIT_SUCCESS;
}

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
