#include <stdio.h>
#include <math.h>

#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){

	int i, j, c;
	double m;
	for (i = 0; i<mat->r-1; i++) {
		if (mat->data[i][i] == 0) {
				fprintf(stderr, "Dzielnik równy 0");
				return 1;
			}
		for (j=i+1; j<mat->r; j++) {
			m = mat->data[j][i] / mat->data[i][i];
			for (c=i; c<=mat->c; c++)
				mat->data[j][c] -= m * mat->data[i][c];
		b->data[j][0] -= m * b->data[i][0];
		}
	}
	return 0;
}