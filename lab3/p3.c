#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/*program używa wskaźnika fcji jako argumentu innej fcji
*pobiera nazwe_fcji, min, max, liczbe krokow, i plik do zapisu 
*wszystko poza nazwa_fcji ma swoje wartosci domyslne
*zwraca komunikaty w razie nie podania fcji lub podania nieistniejacej fcji
*LAB 3			17.10.2014 r.
*/
void tabelka(double (*f) (double), double a, double b, int n, FILE * out){
        int             i;
        double          dx = (b - a) / (n - 1);

        for (i = 0; i < n; i++)
                fprintf(out, "%g %g\n", a + i * dx, f(a + i * dx));
}

double moja(double x)
{
        return 3 * x * x + 2 * x + 1;
}

double sqrtm(double x)
{
	return sqrt(x);
}
double potega2(double x)
{
	return x*x;
}

int main(int argc, char **argv)
{
        /*przypisanie kolejnych argumentow i wartosci domyslnych*/
	char           *fun_name = argc > 1 ? argv[1] : "";
        double          a = argc > 2 ? atof(argv[2]) : 0.;
        double          b = argc > 3 ? atof(argv[3]) : 1.;
        int             n = argc > 4 ? atoi(argv[4]) : 50;

        int             i;

	/*przypisanie pliku i domyslnie ekran*/
        FILE           *out = argc > 5 ? fopen(argv[5], "w") : stdout;

        double          (*wybrana_fun) (double)= NULL;

	/*deklaracja tablicy z funkcjami do wyboru i tablica z ich nazwami*/
        double          (*funkcje[7]) (double)= {cos, sin, tan, moja, atan,sqrtm,potega2};
        char           *nazwy[7] = {"cos", "sin", "tan", "moja", "atan","sqrtm","potega2"};

	/*instrukcja w razie nie wybrania zadnej fcji*/
        if (argc < 2) {
                printf("\n%s: tablicuje wybrana funkcje w zadanym przedziale.\n", argv[0]);
                printf("\n\tWywolanie:\n"
                       "\t\t%s <nazwa-funkcji> [ <start> [ <stop> [ <n> [ <plik> ] ] ] ]\n\n", argv[0]);
                printf("\tGdzie:\n"
                       "\t\t<nazwa-funkcji>:");
      
	          for (i = 0; i < sizeof nazwy / sizeof nazwy[0]; i++)
                        printf("\t%s", nazwy[i]);
        
	        printf("\n");
                printf("\t\t<start>-<stop>:  \tprzedzial - domyslnie <0,1>\n"
                     "\t\t<n>:             \tliczba krokow - domyslnie 50\n"
                 "\t\t<plik>:          \twyniki - domyslnie do stdout\n\n");
        
	        return 0;
        }
       
	/*porówanie wpisanej fcji z mozliwymi i przypisanie wybranej*/
	 for (i = 0; i < sizeof nazwy / sizeof nazwy[0]; i++)
                if (strcmp(nazwy[i], fun_name) == 0)
                        wybrana_fun = funkcje[i];

	/*uruchomienie fcji tabelka z przekazaniem fcji jako argumentu*/
        if (wybrana_fun != NULL)
                tabelka(wybrana_fun, a, b, n, out);
	/*komunikat bledu - nie znaleziono wpisanej fcji w tabeli nazwy*/
	else
                fprintf(stderr, "Nie znam funkcji \"%s\"\n", fun_name);

        
	return 0;
}
