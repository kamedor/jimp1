#include "insort.h"

#include <stdio.h>  // wiadomo po co
#include <stdlib.h> // funkcje atoi, malloc i rand
#include <time.h>   // funkcja time

void printv( double v[], int n ) {  // wypisuje wektor na stdout
	int i;
	int np=  n > MAX_ELEM_2_PRINT ? MAX_ELEM_2_PRINT : n;  // UWAGA: przy kompilacji trzeba zdefiniować MAX_ELEM_2_PRINT
                                                         //   np.: -DMAX_ELEM_2_PRINT=10
	printf( "[" );
	for( i= 0; i < np; i++ )
		printf( " %g", v[i] );
	printf( "%s ]\n", np < n ? " ... " : "" );
}

int
main( int argc, char **argv ) {
	int n= argc > 1 ? atoi( argv[1] ) : 1000;
  int i;

	double *v= malloc( n * sizeof *v );

	srand( argc > 2 ? atoi(argv[2]) : time(NULL) );

	for( i= 0; i < n; i++ )
		v[i] = rand() *10 / (double)RAND_MAX * n;

	printf( "Wygenerowany wektor: " );
	printv( v, n );

	insort( v, n );
	
	printf( "Posortowany wektor: " );
	printv( v, n );

	for( i= 1; i <n; i++ )
		if( v[i-1] > v[i] )
			fprintf( stderr, "Zly algorytm sortowania: v[%d]==%g > v[%d]==%g\n", i-1, v[i-1], i, v[i] );

	return 0;
}
