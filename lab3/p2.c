#include <stdio.h>

void usun_ujemne2(double v[], int *n)
{                                  
        /* Usuwa ujemne elementy z wektora v */
	int		i;
	int		l=*n;
        int       	j=0;
		for(i = 0 ;i < l ;i++ ) {
			if (v[i] >= 0) {    /* jeśli element jest dodatni */
        	                v[j] = v[i];      /* to zapamiętaj go w "nowym"*/
                        	j++;                 /* wektorze */
			}
         	       	else
         	               (*n)--; /* w przeciwnym razie zmniejsz 
                                 * wartosc wskazywana przez n */
		}
}


void pwekt(double *v, int n)
{
        printf("[ ");
        while (n--) {
                printf("%g ", *v);
                v++;
        }
        printf("]");
}

int main()
{
        double          v[] = {-10, 0, 10, -20, 30, 1.1, -2.2, -3.3, 300.003, 1024.5};
        int             n = sizeof v / sizeof v[0];

        printf("Wektor: ");
        pwekt(v, n);
        printf(" (%d elementow)\n", n);

        usun_ujemne2(v, &n);

        printf("Wektor po usunieciu ujemnych elementow: ");
        pwekt(v, n);
        printf(" (%d elementow)\n", n);
        return 0;

}
