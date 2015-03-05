#include <stdio.h>  // wiadomo po co
#include <stdlib.h> // qsort
#include <string.h> // strcmp

int
alphacmp( const void *a, const void *b ) {
	char **ca = (char**)a;
	char **cb = (char**)b;
	return strcmp( *ca, *cb );
	//| ca[0][0]	|**ca 	| typ char** 	| lista wyrazów | coś jak *argv[]	|
	//| ca[0]	| *ca	| typ char*	| wyraz		| coś jak argv [0]	|
	//| ca		| ca	| typ char	| znak		| coś jak 's' lub '\n'	|
	//  ca[1]	  *(ca+1) 
	//  ca[2][1]	  *(*(ca+1)+2) 
}

int
alphacmpZ( const void *a, const void *b ) {
	char *ca = (char*)a;
	char *cb = (char*)b;
	printf("*a=%c *b= %c a=%s b=%s\n",*ca,*cb,ca,cb);
	return -(*ca -*cb);
}


int
main( int argc, char *argv[] ) {
	int i;
/*	
	qsort( argv+1, argc-1, sizeof *argv, alphacmp );

	for( i= 1; i < argc; i++ )
		printf( "%s\n", argv[i] );
*/
	for(i=1;i<argc;i++) {
		qsort( argv[i], strlen(argv[i]), sizeof(char), alphacmpZ);

		printf("\ni=%d %s %ld %ld\n\n",i,argv[i],strlen(argv[i])+1,sizeof(char));
	}
	printf("\n");
	for(i=1;i<argc;i++) {
		printf( "%s\n", argv[i]);
	}

	return 0;
}
