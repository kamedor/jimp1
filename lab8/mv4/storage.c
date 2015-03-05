#include "storage.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

fun_t *find_function(char *funame){
	//stwórz pierwszą jeśli nie ma żadnej
	if( start_fun == NULL ) {
	/*	fun_t *start_fun = malloc( sizeof *start_fun );*/
		start_fun->funame = funame;
		start_fun->next = NULL;
		start_fun->def =NULL;
		start_fun->call =NULL;
		start_fun->proto =NULL;
		return start_fun;
	}
	//znajdź jeśli jest
	fun_t  *tmp = malloc( sizeof *tmp );
	tmp=start_fun;
	while((tmp->next) != NULL){	
		if(strstr(tmp->funame,funame) != NULL) {
			return tmp;
		}
		tmp->next;
	}
	//stwórz kolejną jeśli nie ma
	fun_t *f  = malloc( sizeof *f);
	tmp->next= f;
	f->next= NULL;
	f->def =NULL;
	f->call =NULL;
	f->proto =NULL;
	f->funame= funame;
	return f;	
}

def_t *add_def(def_t *def, int LN, char *inpname ){
	//stwórz pierwszą jeśli nie ma żadnej
	if( def == NULL ) {
		def_t *def = malloc( sizeof *def );
		def->ln = LN;
		def->plik =inpname;
		def->next = NULL;
		return def;
	}
	//przejdź do ostatniej
	def_t *tmp = malloc( sizeof *tmp );
	tmp=def;
	while((tmp->next) != NULL){	
		tmp->next;
	}
	//stwórz kolejną jeśli nie ma
	def_t *nowy = malloc(sizeof *nowy);
	tmp->next= nowy;
	nowy->ln= LN;
	nowy->plik= inpname;
	nowy->next=NULL;
	return nowy;
}

fun_t *store_add_def (char *funame, int LN, char *inpname){
	fun_t *f=find_function( funame);
	f->def= add_def(f->def,LN, inpname);
	return start_fun;
	/*printf("Funkcja %s:\n",f->funame);
	printf("\tDeklaracja:\n");
	printf("\tplik %s, linia: %d\n",f->def->plik,f->def->ln);*/
}

int print_def(){
	if(start_fun == NULL){
		fprintf(stderr, "Blad glupcze\n");
		return -1;
	}
	printf("Funkcja %s:\n",start_fun->funame);
	printf("\tDeklaracja:\n");
	printf("\tplik %s, linia: %d\n",start_fun->def->plik,start_fun->def->ln);
	return 0;
}
