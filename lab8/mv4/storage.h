#ifndef _STORAGE_H
#define _STORAGE_H

#include <stdlib.h>
	typedef struct s1{
		int ln;
		char *plik;
		struct s1 *next;
	} def_t;

	typedef struct s0{
		def_t *def;
		def_t *call;
		def_t *proto;
		char* funame;
		struct s0 *next;
	} fun_t, *store_t;
	
	store_t start_fun= malloc( sizeof start_fun );
	
	fun_t *find_function( char *funame);
	def_t *add_def(def_t *def, int LN, char *inpname );
	int print_def();
	//definicja funkcji funkcja(x){printf("x");}
	fun_t *store_add_def (char *funame, int LN, char *inpname);
      
	//prototyp funkcja(x);
	void store_add_proto (char *funame, int  LN, char *inpname);
      
	//wywołanie {funkcja(x);}
	void store_add_call (char *funame, int LN, char *inpname);

#endif
