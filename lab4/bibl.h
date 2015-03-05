#ifndef _BIBL_H_                /* zabezpieczenie przed wielokrotnym
                                 * wlaczeniem tego pliku */
#define _BIBL_H_

#include <stdio.h>

/* Prototypy funkcji */

/*
 * read: czyta z pliku p wektor double v[], nie dluzszy niz max_l_e elementow
 * w v musi byc miejsce na co najmniej n elementow zwraca liczbe
 * przeczytanych elemento w razie sukcesu, -1 w razie bledu format wektora to
 * <liczba_elementow> [ <element> ... ] np. 3 [ 1.2 4.5, 7.8]
 */
int             read(FILE * p, double v[], int max_l_e);

/*
 * L2: oblicza norme L2 (pierwiastek z sumy kwadratow) wektora double v[] o
 * dlugosci n
 */
double           L2(double v[], int n);

/*
 * dot_product: oblicza iloczyn skalarny wektorow double v[] i u[] v i u maja
 * dlugosc n
 */
double           dot_product(double v[], double u[], int n);

/*liczy iloczyn wektorowy dwoch wektorow trojwymiarowych*/
double		iloczyn_vect(double v[], double u[], double w[], int n);

/*licz norme L nieskonczonosc i zwarca jej wynik*/
double          Lnieskon(double v[], int n);

/*wczytuje wektor dowolnej wielkosci w formacie cokolwiek = < a b c ... z >*/
int             moj_read(FILE * p, double v[], int max_l_e);

#endif
