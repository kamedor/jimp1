#include "vect.h"
#include <stdio.h>
#include <stdlib.h>
vect_t
dodaj_do_wektora (vect_t l, int n)
{
  if (l == NULL)
    {
      vect_t l = malloc (sizeof *l);
      l->akt_elem = 0;
      l->max_elem = 2;
      l->elem= (int*)malloc(l->max_elem * sizeof(int));
      return l;
    }
  else if (l->akt_elem >= l->max_elem)
    {
      int *tmp;
      l->max_elem *=2;
      tmp = (int*)realloc(l->elem, l->max_elem*sizeof(int));
      l->elem = tmp;
    }
  l->elem[l->akt_elem] = n;
  l->akt_elem = l->akt_elem+1;
  printf("n=%d, akt_elem=%d, l->elem[akt_elem]=%d\n",n,l->akt_elem,l->elem[l->akt_elem]);
  return l;
}
