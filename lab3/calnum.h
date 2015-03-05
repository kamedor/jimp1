/** Prototyp funcji calkujacej numerycznie f. jednej zmiennej.
 *  f to funkcja podcalkowa
 *  <a,b> to przedzial calkowania
 *  n to liczba podprzedzialow (posrednio okresla dokladnosc) */
double calnum ( double (*f)( double ), double a, double b, int n );
