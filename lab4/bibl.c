#include "bibl.h"

#include <math.h>		/* dzieki temu kompilator sprawdzi, czy
				 * dobrze uzywamy funkcji sqrt */

/* Definicje funkcji */

/*
 * read: czyta z pliku p wektor double v[], nie dluzszy niz max_l_e elementow
 * w v musi byc miejsce na co najmniej n elementow zwraca liczbe             
 * przeczytanych elemento w razie sukcesu, -1 w razie bledu                  
 *                                                                           
 * Format wektora w pliku - np.:  5 [ 0.1 1.2 2.3 3.4 4.5 ]                  
 */
int
read (FILE * p, double v[], int max_l_e)
{
  int n, i;			/* zmienne robocze */

  if (fscanf (p, "%i", &n) != 1 || n <= 0 || n > max_l_e)
    {				/* probujemy przeczytac
				 * liczbe elementow */
      /*
       * nie udalo sie (fscanf zwrocila wartosc inna niz 1 lub
       * wczytana wartosc jest niedodatnia albo zbyt duza )
       */
      return -1;
    }
  while ((i = fgetc (p)) == ' ')	/* pomijamy spacje po liczbie
					 * elementow */
    ;

  /* mamy znak rozny od spacji - powinien to byc znak '[' */
  if (i != '[')
    return -1;			/* nie jest - bledny format pliku */

  /* teraz czytamy n liczb */
  for (i = 0; i < n; i++)
    if (fscanf (p, "%lf", &(v[i])) != 1)	/* fscanf powinno zawsze
						 * zwracac 1 - jesli
						 * zwroci cos innego */
      return -1;		/* to znaczy, ze format pliku jest
				 * zly */

  /* mamy liczby, teraz szukamy zamykajacego nawiasu: */
  while ((i = fgetc (p)) == ' ')	/* pomijamy spacje */
    ;

  /* mamy znak rozny od spacji - powinien to byc znak ']' */
  if (i != ']')
    return -1;			/* nie jest - bledny format pliku */

  /*
   * jesli doszlismy juz tu, to wszystko jest ok, mamy w wektorze n
   * liczb
   */
  return n;
}

/*
 * L2: oblicza norme L2 (pierwiastek z sumy kwadratow) wektora double v[] o
 * dlugosci n
 */
double
L2 (double v[], int n)
{
  int i;
  int l2 = 0;			/* wazne jest, aby nadac l2 wartosc
				 * poczatkowa */
  for (i = 0; i < n; i++)
    l2 += v[i] * v[i];
  return sqrt (l2);
}

/*
 * dot_product: oblicza iloczyn skalarny wektorow double v[] i u[] v i u maja
 * dlugosc n
 */
double
dot_product (double v[], double u[], int n)
{
  int i;
  double dp = 0;		/* wazne jest, aby nadac dp wartosc
				 * poczatkowa */
  for (i = 0; i < n; i++)
    dp += v[i] * u[i];
  return dp;
}

double
iloczyn_vect (double v[], double u[], double w[], int n)
{
  w[0] = v[1] * u[2] - v[2] * u[1];
  w[1] = (v[0] * u[2] - v[2] * u[0]) * (-1);
  w[2] = v[0] * u[1] - v[1] * u[0];
  return 0;
}

double
Lnieskon (double v[], int n)
{
  double L;
  int i;

  L = fabs (v[0]);
  for (i = 0; i < n; i++)
    if (L < fabs (v[i]))
      L = fabs (v[i]);

  return L;
}

/*wczytuje wektor dowolnej wielkosci w formacie cokolwiek_= < a b c ... z >
 * gdzie '_' oznacza 1 spację			*/
int
moj_read (FILE * p, double v[], int max_l_e)
{
  int n, i;

  while ((i = fgetc (p)) != ' ')
    ;

  if ((i = fgetc (p)) != '=')
    return -1;

  while ((i = fgetc (p)) == ' ')
    ;
  /* mamy znak rozny od spacji - powinien to byc znak '<' */

  if (i != '<')
    return -1;			/* nie jest - bledny format pliku */

  n = 0;			/*n powie ile udało się odczytać elementów */

  for (i = 0; i < max_l_e; i++)
    {
      if (fscanf (p, "%lf", &(v[i])) != 1)
	break;			/*jeśli w wektorze jest cos innego niz liczba wyskakuje odrazu poza petle */
      else
	n++;
    }
  /* fscanf powinno zawsze
   * zwracac 1 - jesli
   * zwroci cos innego */

  /* mamy liczby, teraz szukamy zamykajacego nawiasu: */
  while ((i = fgetc (p)) == ' ')	/* pomijamy spacje */
    ;

  /* mamy znak rozny od spacji - powinien to byc znak '>' */
  if (i != '>')
    return -1;			/* nie jest - bledny format pliku */

  /*
   * jesli doszlismy juz tu, to wszystko jest ok, mamy w wektorze n
   * liczb
   */
  return n;
}
