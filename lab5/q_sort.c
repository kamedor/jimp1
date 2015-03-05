# include "q_sort.h"

int divide( double v[], int f, int l ) {
  double tmp; // zmienna tymczasowa do zmiany elementów
	int s= f;   // dzielimy ze względu na pierwszy element
//	f++;        // opuść pierwszy element
	while( f < l ) {
		while( f < l && v[f] <  v[s] )
			f++;
		while( f < l && v[l] > v[s] )
			l--;
		if( f < l ) {
			tmp= v[f];
			v[f]= v[l];
			v[l]= tmp;
		}
	}
  // zamieniamy element v[s] z v[f]
  // aby v[s] znalazł się pomiędzy
  // mniejszymi i nie-większymi od niego
	tmp = v[s];
  v[s] = v[f];
  v[f] = tmp;
	return f;
}

void qsort_rec( double v[], int first, int last ) {
                // wygodniej jest zapisać tę funkcję rekurencyjną
                // posługując się indeksem początku i końca wektora
   if( first < last ) {
      int m= divide( v, first, last );
      qsort_rec( v, first, m-1 );
      qsort_rec( v, m+1, last );
   }
}

void q_sort( double v[], int n ) {  // to jest tylko opakowanie, aby wywołanie
                                   // wyglądało tak samo, jak insort
   qsort_rec( v, 0, n-1 );
}

