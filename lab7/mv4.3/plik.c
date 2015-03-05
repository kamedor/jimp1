#include <stdio.h>
#include <stdlib.h>

#include "plik.h"

FILE *
wczytaj_plik (int argc, char **argv)
{
  FILE *fin = argc > 1 ? fopen (argv[1], "r") : stdin;
  if (fin == NULL)
    {
      fprintf (stderr, "%s: błąd: nie mogę czytać pliku %s\n", argv[0],
	       argv[1]);
      exit (EXIT_FAILURE);
    }
  return fin;
}
