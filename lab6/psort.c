#include <stdio.h>  // wiadomo po co
#include <stdlib.h> // qsort
#include <string.h> // strcmp

#define BUFSIZE 8192    // zakładamy, że linie będą krótsze niż 8kB
#define MAXLINES 1000000 // maksymalna liczba linii

int
alphacmp( const void *a, const void *b ) {
	char **ca = (char**)a;
	char **cb = (char**)b;
	return strcmp( *ca, *cb );
}

int
main( int argc, char **argv ) {
	int i;
	char *kopia[MAXLINES];
	int ile_linii;

	char buf[BUFSIZE];

	FILE *in= argc > 1 ? fopen( argv[1], "r" ) : stdin;

	if( in == NULL ) {
		fprintf( stderr, "%s: błąd: nie mogę czytać pliku %s\n", argv[0], argv[1] );
		return EXIT_FAILURE;
	}

	ile_linii= 0;
	while( fgets( buf, BUFSIZE, in ) != NULL ) {
		if( ile_linii < MAXLINES ) {
			if( (kopia[ile_linii]= malloc( (strlen(buf)+1) * sizeof( char ) )) == NULL ) {
				fprintf( stderr, "%s: błąd: zbyt wiele danych (brak pamięci)\n", argv[0] );
				return EXIT_FAILURE;
			}
			strcpy( kopia[ile_linii], buf );
			ile_linii++;
		} else {
			fprintf( stderr, "%s: błąd: zbyt wiele linii wejścia\n", argv[0] );
			return EXIT_FAILURE;
		}
	}
	
	qsort( kopia, ile_linii, sizeof *kopia, alphacmp );

	for( i= 0; i < ile_linii; i++ )
		printf( "%s", kopia[i] );

	return EXIT_SUCCESS;
}
