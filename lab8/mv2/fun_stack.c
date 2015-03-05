#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fun_stack.h"

int top_of_fun_stack( void ) {
	lista tmp; 		// wskaznik na aktualny element
	if( stos == NULL ) {
		fprintf( stderr, "Stos jest pusty\n" );
		return -1;
	}
	tmp = stos;
	while( tmp->next != NULL ) {
		tmp = tmp->next;
	}
	return tmp->par_level;
}

void put_on_fun_stack( int par_level, char *funame ) {
	lista tmp;		// wskaznik na aktualny element
	if( stos == NULL ) {
		stos = malloc( sizeof * tmp );
		if( stos == NULL ) {
			fprintf(stderr, "Nie zaalokowano pamieci\n");
			return;
		}
		tmp = stos;
	} else {
		tmp  = stos;
			while( tmp->next != NULL ) {
			tmp = tmp->next;
		}
		tmp->next = malloc ( sizeof * tmp->next );
		if( tmp->next == NULL ) {
			fprintf(stderr, "Nie zaalokowano pamieci\n");
			return;
		}
		tmp = tmp->next;
	}
	tmp->next = NULL;
	tmp->par_level = par_level;
	tmp->funame = malloc( (strlen( funame )+1) * sizeof * tmp->funame );
	if( tmp->funame == NULL ) {
		fprintf(stderr, "Nie zaalokowano pamieci\n");
		return;
	}
	strcpy( tmp->funame, funame );
}

char *get_from_fun_stack( void ) {
	lista tmp;		// wskaznik na aktualny element
	lista ptmp;		// wskaznik na poprzedni element
	char *funame;  	// zwracana wartosc
	if( stos == NULL ) {
		fprintf( stderr, "Stos jest pusty\n" );
		return -1;
	}
	tmp  = stos;
	ptmp = stos;
	while( tmp->next != NULL ) {
		ptmp = tmp;
		tmp = tmp->next;
	}
	funame = malloc( (strlen( tmp->funame )+1) * sizeof * funame );
	strcpy( funame, tmp->funame );
	free( tmp );
	// jezeli doszlismy do korzenia listy, to wyzerujmy wskaznik na nia
	if( tmp == stos)
		stos = NULL;
	else
		ptmp->next = NULL;	
	return funame;
}
