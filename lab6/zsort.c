#include <stdio.h>  // wiadomo po co
#include <stdlib.h> // qsort
#include <string.h> // strlen

int
charcmp( const void *a, const void *b ) {
	char *ca = (char*)a;
	char *cb = (char*)b;
	return  *ca - *cb;
}

int
main( int argc, char **argv ) {
	int i;
	

	for( i= 1; i < argc; i++ ) {
	  qsort( argv[i], strlen(argv[i]), sizeof( char ), charcmp );
		printf( "%s\n", argv[i] );
	}

	return 0;
}
