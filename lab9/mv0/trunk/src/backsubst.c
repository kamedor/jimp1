#include "backsubst.h"
#include <stdio.h>
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
				int i,j;
				double suma_poprzednich;
				
				if(mat->r != mat->c){
					fprintf(stderr, "błąd nieprawidłowych rozmiarów macierzy\n");
					return 2;
				}
				
				for(i= (x->r)-1; i>=0; i--){
					suma_poprzednich=0;
					
					for (j=(x->r)-1; j>i ; j--){
						suma_poprzednich=suma_poprzednich - x->data[j][0]*mat->data[i][j];
					}
					
					if (mat->data[i][i] != 0){
						x->data[i][0]= (b->data[i][0] + suma_poprzednich) / (mat->data[i][i]);
					}else{
						fprintf(stderr,"Błąd dzielenia przez zero.\n");
						return 1;
					}
				}
				return 0;
}


