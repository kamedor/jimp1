#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LL 7 /*orginalnie bylo 5*/
/*fcja losuje n liczb typu double z przedziału min max i zapisuje do wyjscia out*/ 

int main(int argc, char *argv[])
{
        int             n = argc > 1 ? atoi(argv[1]) : 10;      /* ile liczb? domyslnie
                                                                 * 10 */
        double          min = argc > 2 ? atof(argv[2]) : 0.0;   /* minimalna możliwa
                                                                 * wartość? domyślnie
                                                                 * 0 */
        double          max = argc > 3 ? atof(argv[3]) : 1.0;   /* maksymalna możliwa
                                                                 * wartość? domyślnie
                                                                 * 1 */

        FILE           *out = argc > 4 ? fopen(argv[4], "w") : stdout;  /* do jakiego pliku
                                                                         * pisać? domyślnie na
                                                                         * konsolę */
        /*
         * fopen otwiera plik, którego nazwę określa pierwszy argument
         * drugi argument mówi, w jakim celu plik otwieramy - tutaj "w"
         * (write) określa, że chcemy coś do niego zapisać. fopen zwróci
         * specjalną wartość - NULL, jeśli pliku nie uda się otworzyć
         */

        int             i;

        if (out == NULL) {      /* sprawdzamy, czy udało się otworzyć plik
                                 * podany jako argv[4] */
                /* Uwaga: stdout != NULL (na pewno) */
                fprintf(stderr, "%s: nie moge pisac do %s\n", argv[0], argv[4]);
                return 1;
        }

        /*
         * Petla drukujaca po LL liczb w jednej linii Do zmiany linii
         * używana jest sztuczka z formatem drukujacym \n gdy i jest
         * wielokrotnoscia LL
         */
        for (i = 0; i < n; i++) {
                double          ulamek = (double)rand() / RAND_MAX;
                fprintf(out, "%g%c",
                        min + (max - min) * ulamek, (i % LL == LL - 1 ? '\n' : ' ')
                        );
        }
        if (i % LL != 0)
                fprintf(out, "\n");

        /*
         * W zasadzie powinniśmy zamknąc plik, ale zaraz kończymy, więc i
         * tak zrobi to za nas system. A niedobrze byłoby zamknąć stdout !
         * 
         * fclose( out );
         */

        return 0;
}
