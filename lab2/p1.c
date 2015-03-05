#include <stdio.h>		/* dla printf */
#include <stdlib.h>
/*program przyjmuje z stdin kolejne liczby jako argument
 *zapisuje je do wektora
 *wyswietla wektor oraz sume
 *odporna na podanie innych wartosci niz liczba*/
double 
sum(double v[], int n)
{
	/*
	 * Funkcja oblicza i zwraca sume elementow n-elementowego wektora v
	 */
	double		s = v[0];
	int i;
/*	while (--n)
		s += v[n]; */

	for ( i = 1; i <n ; i ++ )
		s += v[i];

	return s;
}

void 
pwekt(double v[], int n)
{
	/* Ladne wypisywanie wektora na standardowe wyjscie */
	int		i;
	printf("[");
	for (i = 0; i < n; i++)
		printf(" %g", v[i]);
	printf(" ]");
}

int 
main(int argc, char *argv[])
{
	double		r       [1000];	/* jesli ktos poda wiecej argumentow
					 * - bedzie bieda! */
	int		i;

	int		l = argc - 1;	/* liczba el. wektora */

	for (i = 1; i < argc; i++)	/* zaczynamy od drugiego el. argv */
		r[i - 1] = atof(argv[i]);	/* atof: ASCII to Float */

	pwekt(r, l);	/* można tak, ale lepiej l zmiast argc-1 */

	printf(", suma elementow = %g\n", sum(r, l));

	printf("wektor ma %d elementow\n", l);	/* zwróćmy uwagę, że
						 * funkcja sum nie "popsula"
						 * zmiennej j */

	return 0;
}
