#include <stdio.h>
#include <math.h>
#define NMAX 1000000
/*program wczytuje wektor z pliku lub klawiatury i podaje sume, srednia, dl euklidesowa itp. */
/*WAZNE
*kompiluje się go z flaga -lm na koncu (dodanie biblioteki matematycznej) (chyba)*/

double srednia( double t[], int n){ /*fcja liczy srednia artymetyczna wektora*/
	int i;
	double srednia=0;
	for ( i = 0 ; i < n ; i++)
		srednia = srednia + t[i];
	srednia = srednia / n;
	return srednia;
}

double mini( double t[], int n){ /*fcja wyswietla najmniejszy element wektora*/
	int i;
	double min=t[0];
	for (i = 0; i < n; i++) {
		if(t[i]<min)
			min = t[i];
	}

	return min;
}

double dleuk( double t[], int n){/*fcja liczy dl euklidesowa wektora*/
	int i;
	double suma2 = 0.0;
	for(i = 0; i<n;i++)
		suma2 = suma2 + ( t[i] * t[i]) ;
	
	return sqrt(suma2);
}


int	main(int argc, char *argv[])
{
        /*jesli podano wczytaj plik, else z klawiatury*/
	FILE           *in = argc > 1 ? fopen(argv[1], "r") : stdin;

        if (in != NULL) {
                double          sum = 0;
                double          sum2 = 0;
                double          x;
                double		y[NMAX];
		int             n = 0;


               while (fscanf(in, "%lf", &x) == 1) {
			sum += x;
                        sum2 += x * x;
                        n++; 
                        y[n]= x;
                }	 




                fclose(in);

                printf("\tn=%d, sum=%g, avg=%g std_dev=%g\n",
                       n, sum, sum / n, sqrt(n * sum2 - sum * sum) / n
                      );
		printf("srednia wynosi %f \n" ,  srednia(y,n) ) ;
        	printf("wartość minimalna to %f \n" , mini(y,n) );
		printf("Dlugosc eukildesowa to %f \n", dleuk(y,n) );

	        return 0;
        } else
                return 1;
}
