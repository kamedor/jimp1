#include <stdio.h>  // wiadomo po co
#include <stdlib.h> // qsort
#include <string.h> // strstr

#define BUFSIZE 8192    // zakładamy, że linie będą krótsze niż 8kB

int
main( int argc, char **argv ) {
  int ile_linii;
	char buf[BUFSIZE];

	char *str= argc > 1 ? argv[1] : NULL;

	FILE *in= argc > 2 ? fopen( argv[2], "r" ) : stdin;

	if( str == NULL ) {
		fprintf( stderr, "%s: błąd: proszę podac napis do wyszukiwania\n", argv[0] );
		return EXIT_FAILURE;
	}

	if( in == NULL ) {
		fprintf( stderr, "%s: błąd: nie mogę czytać pliku %s\n", argv[0], argv[2] );
		return EXIT_FAILURE;
	}

	ile_linii= 0;
	while( fgets( buf, BUFSIZE, in ) != NULL ) {
		ile_linii++;
		if( strstr( buf, str ) != NULL )
			printf( "[%d] %s",ile_linii, buf );
			
	}
	
	return EXIT_SUCCESS;
}
