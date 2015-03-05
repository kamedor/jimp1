#include <stdio.h>		// wiadomo po co
#include <stdlib.h>
#include <string.h>		// strstr

#include "skorowidz.h"

#define BUFSIZE 8192

void
wyszukaj (skorowidz_t skorowidz, FILE * in)
{

  int *p;
  int *k;
  int i;
  int nr_linii;
  char buf[BUFSIZE];

  nr_linii = 0;
  while (fgets (buf, BUFSIZE, in) != NULL)
    {
      nr_linii++;
      for (i = 0; i < skorowidz.ile_slow; i++)
	{
	  p = strstr (buf, skorowidz.slowa[i]);
	  k = p + strlen (skorowidz.slowa[i]);
	  if ((p != NULL) && (((p == &buf[0]) || (*(p - 1) < 'A')
			       || ((*(p - 1) > 'Z') && (*(p - 1) < 'a'))
			       || (*(p - 1) > 'z'))
			      && (((k - 1) == &buf[BUFSIZE]) || (*k < 'A')
				  || ((*k > 'Z') && (*k < 'a'))
				  || (*k > 'z'))))
	    {
	      dodaj_pozycje_skorowidza (&skorowidz, i, nr_linii);
	    }
	}
    }
}
