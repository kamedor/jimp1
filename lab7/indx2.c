#include <stdio.h>  // wiadomo po co
#include <stdlib.h> 
#include <string.h> // strstr

#define BUFSIZE 8192   // zakładamy, że linie będą krótsze niż 8kB
#define MAXLINII 1000  // zakładamy, że słowo będzie wystepować w nie więcej, niż 1000 liniach

#define MAXSLOW 100     // skorowidz dla nie więcej, niż 100 słów

void zainicjuj_skorowidz( int argc, char **argv, int *ile_slow, char *slowa[], int linie[][MAXLINII] );

void wypisz_skorowidz( int ile_slow, char *slowa[], int linie[][MAXLINII] );

int
main( int argc, char **argv ) {
  int i;
  int ile_linii;
  char buf[BUFSIZE];

  FILE *in= argc > 1 ? fopen( argv[1], "r" ) : stdin;

  char *slowa[MAXSLOW];   // słowa do wyszukiwania
  int ile_slow;
  int linie[MAXSLOW][MAXLINII]; // tu zapisujemy numery linii
                              // linie[i][0] to licznik
                              // linie[i][1] ... to nr-y linii, w których wystąpiło słowo

  zainicjuj_skorowidz( argc, argv, &ile_slow, slowa, linie );

  if( ile_slow == 0 ) {
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
    for( i= 0; i < ile_slow; i++ )
      if( strstr( buf, slowa[i] ) != NULL ) {
        linie[i][0]++;
        linie[i][linie[i][0]]= ile_linii;
      }
  }

  wypisz_skorowidz( ile_slow, slowa, linie );

  return EXIT_SUCCESS;
}

void zainicjuj_skorowidz( int argc, char **argv, int *ile_slow, char *slowa[], int linie[][MAXLINII] ) {
	int i;
	*ile_slow= 0;
  for( i= 2; i < argc; i++ ) {
    slowa[*ile_slow]= argv[i];
    linie[*ile_slow][0]= 0;
    ++ *ile_slow;
  }
}

void wypisz_skorowidz( int ile_slow, char *slowa[], int linie[][MAXLINII] ) {
  int i,j;

  for( i= 0; i < ile_slow; i++ ) {
    if( linie[i][0] > 0 ) {
      printf( "słowo \"%s\" wystąpiło w liniach:", slowa[i] );
      for( j= 1; j <= linie[i][0]; j++ )
        printf( " %d", linie[i][j] );
      printf( "\n" );
    } else {
      printf( "nie napotkano słowa \"%s\"\n", slowa[i] );
    }
  }
}
