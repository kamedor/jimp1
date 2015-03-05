#include "fun_stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TESTOW 2 // lista testó w inicial_fun_stack i get_from
#define OVERLOAD 10000000

int nr_testu= 0; // służy do wypisywania który test jest obecnie przetwarzany
char *nz_funkcji[TESTOW] = {"funkcja0","funkcja1"};



void top_pusty_stos(){// sprawdz pobranie topu z pustego stosu
  nr_testu++;
  printf("Test %d: Wyświetlenie top z pustego stosu\n", nr_testu);
  if(top_of_funstack() ==0)
    printf("Test %d: BŁĄD Funkcja top_of_funstack nie obsluguje bledu przy pustym stosie\n");
  else
	printf("Test %d: OK! \n\n", nr_testu);
}

void get_pusty_stos(){ //sprawdza pobranie get z pustego stosu
  nr_testu++;
  printf("Test %d: Pobranie funame z pustego stosu\n", nr_testu);
  if(get_from_fun_stack() == 0)
	 printf("Test %d: BŁĄD - Funkcja get_from_funstack nie obsluguje bledu przy pustym stosie \n\n", nr_testu);
else
	printf("Test %d: OK! \n\n", nr_testu);
}

int inicial_fun_stack(){  //spradza inicjację funkcji
  nr_testu++;
  printf("Test %d: Dodawanie elementów na stos\n", nr_testu);
  int i;
  for(i=0; i<TESTOW; i++){
    put_on_fun_stack(i,nz_funkcji[i]);
//	printf("Wywołanie %d: %s\n",i, szczyt_stosu->funame);  
   if((strstr(nz_funkcji[i],szczyt_stosu->funame))==NULL){
      printf("Test %d: BŁĄD - nie poprawne dodanie funame w %d wywołaniu \n\n", nr_testu,i);
      return 1;
		}
  }
  printf("Test %d: OK! \n\n", nr_testu);
  return 0;
}

int get_from(){ // sprawdza pobieranie z funkcji!
  nr_testu++;
  printf("Test %d: Pobieranie elementów ze stosu\n",nr_testu);
  int i;
  for (i=0; i<TESTOW; i++){
	char *tmp = get_from_fun_stack();
  //  printf("wywołanie %d: %s\n", i,tmp);
		if((strcmp(nz_funkcji[i],tmp))==NULL){
       printf("Test %d: BŁĄD - nie poprawne pobranie funame w %d wywołaniu \n\n", nr_testu,i);
      return 1;
		}
  }
	printf("Test %d: OK! \n\n", nr_testu);
  return 0;
}

int put_over_load(){
	int i;
	nr_testu++;
  printf("Test %d: Próba przeładowania stosu - wywołanie %d razy\n",nr_testu,OVERLOAD);
	for(i=0; i<TESTOW; i++){
    put_on_fun_stack(i,nz_funkcji[i]);
//	printf("Wywołanie %d: %d, %s\n",i,szczyt_stosu->par_level, szczyt_stosu->funame); 
		if((strstr(nz_funkcji[i],szczyt_stosu->funame))==NULL){
       printf("Test %d: BŁĄD - nie dodanie pobranie funame w %d wywołaniu \n\n", nr_testu,i);
      return 1;
		}
  }
	 for(i=TESTOW; i<OVERLOAD; i++){
    put_on_fun_stack(i,"funkcja");
//		printf("Wywołanie %d: %d, %s\n",i,szczyt_stosu->par_level, szczyt_stosu->funame);  
   if(i != (szczyt_stosu->par_level)){
      printf("Test %d: BŁĄD - nie dodanie pobranie funame w %d wywołaniu \n\n", nr_testu,i);
      return 1;
		}
  }
  printf("Test %d: OK! \n\n", nr_testu);
return 0;
}

int get_over_load(){
	int i;
	nr_testu++;
	 printf("Test %d: Próba przeładowania stosu cz.2. - pobranie %d elementów z testu %d \n",nr_testu,OVERLOAD,nr_testu-1);
	for (i=0; i<OVERLOAD; i++){
	char *tmp = get_from_fun_stack();
		if(i<3 && ((strcmp(nz_funkcji[i],tmp))==NULL)){
       printf("Test %d: BŁĄD - nie poprawne pobranie funame w %d wywołaniu \n\n", nr_testu,i);
      return 1;
		}
  }
  printf("Test %d: OK! \n\n", nr_testu);
  return 0;
}

int main(int argc, char **argv){ // main uruchamia 4 testy
	printf("Program przeprowadzi 6 testów\n\n");
	top_pusty_stos();
	get_pusty_stos();
	inicial_fun_stack();
	get_from();
	put_over_load();
	get_over_load();
}
