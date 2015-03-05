#include <stdio.h>

void 
pwekt(int *v, int n)
{
        printf("[ ");
        while (n--) {
                printf("%i ", *v);
                v++;
        }
        printf("]");
}

int 
main()
{
        int          v[] = {10, 20, 30, 1.1, 2.2, 3.3};
        int         *pv;

				printf( "Wektor: " );
				pwekt( v, sizeof v / sizeof v[0] );
				printf( "\n" );

        pv = &v[0];
       printf("Pierwszy element: %i\n", *pv);

        pv = v;
        printf("Pierwszy element: %i\n", *pv);

        pv++;
        printf("Drugi element: %i\n", *pv);

        pv = v + 4;
        printf("Piaty element: %i\n", *pv);

        printf("Odleglosc poimiedzy piatym a pierwszym elementem: %ld\n", pv - v);

        return 0;
}
