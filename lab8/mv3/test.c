#include <stdio.h>
#include "fun_stack.h"
#include <stdlib.h>
#include <string.h>
#define TESTOW 2 // lista testó w inicial_fun_stack i get_from

int nr_testu= 0; // służy do wypisywania który test jest obecnie przetwarzany
char *nz_funkcji[TESTOW];

nz_funkcji[0]="funkcja0";
nz_funkcji[1]="funkcja1";

void top_pusty_stos(){// sprawdz pobranie topu z pustego stosu
  nr_testu++;
  printf("Test %d: top_pusty_stos\n", nr_testu);
  if(top_of_funstack() ==0)
    fprintf(stderr, "Funkcja top_of_funstack nie obsluguje bledu przy pustym stosie");
}

void get_pusty_stos(){ //sprawdza pobranie get z pustego stosu
  nr_testu++;
  printf("Test %d: get_pusty_stos\n", nr_testu);
  get_from_fun_stack();
}

int inicial_fun_stack(){  //spradza inicjację funkcji
  nr_testu++;
  printf("Test %d: inicial_fun_stack.\n", nr_testu);
  int i;
	/*char *nz_funkcji[TESTOW];
  nz_funkcji[0]="funkcja0";
  nz_funkcji[1]="funkcja1";*/
  for(i=0; i<TESTOW; i++){
    put_on_fun_stack(i,nz_funkcji[i]);
	printf("Wywołanie %d: %s\n",i, szczyt_stosu->funame);  
   if((strstr(nz_funkcji[i],szczyt_stosu->funame))==NULL){
      fprintf(stderr,"Błąd: niepomyślny test %d\n",nr_testu);
      return 1;
		}
  }
  printf("Test %d: OK! \n\n", nr_testu);
  return 0;
}

int get_from(){ // sprawdza pobieranie z funkcji
  nr_testu++;
  printf("Test %d: get_from\n",nr_testu);
  int i;
  for (i=0; i<TESTOW; i++){
	char *tmp = get_from_fun_stack;
    printf("wywołanie %d: %s\n", i,tmp);
		if((strcmp(nz_funkcji[i],tmp))==NULL){
      fprintf(stderr,"Błąd: niepomyślny test %d\n",nr_testu);
      return 1;
		}
  }
	printf("Test %d: OK! \n\n", nr_testu);
  return 0;
}

int main(int argc, char **argv){ // main uruchamia 4 testy
	top_pusty_stos();
	get_pusty_stos();
	inicial_fun_stack();
	get_from();
}
