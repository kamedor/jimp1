#include <stdio.h>
#include "calnum.h"
/*fcja liczy calke metoda trapezow
 *musi byc kompilowana:cc -Wall -ansi -pedantic test.c calnum.c -o test -lm
 */
double calnum(double (*f) (double), double a, double b, int n){
	int             i;
	double 		x = (b - a)/n;
	double 		y;
	double		wynik=0.0;

	for(i=0;i<n;i++){
		y = ( f(a + (i*x)) + f( a+((i+1)*x ) ) )/2*x; 
		wynik = wynik + y;
	}

	return wynik;
}
