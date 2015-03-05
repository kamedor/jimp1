#include <stdio.h>
#include <stdlib.h>

#include "bibl.h"		/* dzieki temu kompilator moze sprawdzic, czy
				 * dobrze wywolujemy funkcje z naszej
				 * biblioteki */

int
main (int argc, char *argv[])
{
  double w_1[10];
  double w_2[10];
  int n1;
  int n2;
  int i;

  FILE *we = argc > 1 ? fopen (argv[1], "r") : stdin;	/* jesli argc > 1 to
							 * program zostal
							 * wywolany z argumentem
							 * - probujemy otworzyc
							 * taki plik do czytania */

  if (we == NULL)
    {				/* stdin != NULL, a wiec to mozliwe tylko,
				 * gdy argv[1] zawiera cos, co nie jest nazwa
				 * istniejacego pliku */
      fprintf (stderr, "Plik wejsciowy %s nie istnieje!\n", argv[1]);
      exit (1);
    }
//  n1 = read (we, w_1, 10);	/* czytamy z wejscia wektor i pakujemy go
//				 * do w_1 */
    n1 = moj_read (we,w_1,10);


  if (n1 > 0)
    {
      printf ("Wczytano %i-elementowy wektor:\n( ", n1);
      for (i = 0; i < n1; i++)
	printf ("%f ", w_1[i]);
      printf (")\n");
    }
  else
    {
      fprintf (stderr,
	       "Wystapil blad przy wczytywaniu wektora: kod bledu=%i\n", n1);
      return 1;
    }

  printf ("Norma L2 wczytanego wektora = %f\n", L2 (w_1, n1));

//  n2 = read (we, w_2, 10);	/* czytamy z wejscia wektor i pakujemy go
//				 * do w_2 */
    n2 = moj_read (we,w_2,10);

  if (n2 > 0)
    {
      printf ("Wczytano %i-elementowy wektor:\n( ", n2);
      for (i = 0; i < n2; i++)
	printf ("%f ", w_2[i]);
      printf (")\n");
    }
  else
    {
      fprintf (stderr,
	       "Wystapil blad przy wczytywaniu wektora: kod bledu=%i\n", n2);
      return 1;
    }

  printf ("Norma L2 wczytanego wektora = %f\n", L2 (w_2, n2));

  if (n1 == n2)
    {
      printf ("Iloczyn skalarny wczytanych wektorow = %f\n",
	      dot_product (w_1, w_2, n1));
    }
  else
    {
      printf
	("Wczytane wektory maja rozna dlugosci i nie mozna ich pomnozyc przez siebie\n");
    }

  if (n1 == n2 && n1 == 3)
    {
      double w_3[3];
      iloczyn_vect (w_1, w_2, w_3, n1);
      printf ("Wynik iloczynu wektorowego: [ ");
      for (i = 0; i < 3; i++)
	printf ("%f\t ", w_3[i]);
      printf ("]\n");
    }
  else
    {
      printf("Iloczyn wektrorowy nie może być policzony - jeden z wektorow nie jest trójwymiarowy\n");
    }
  
  printf ("Moja norma wektora 1: %f\n", Lnieskon (w_1, n1));
  printf ("Moja noram wektora 2: %f\n", Lnieskon (w_2, n1));


  return 0;
}
