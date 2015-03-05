#include <stdio.h>		// wiadomo po co
#include <stdlib.h>		// qsort
#include <string.h>		// strstr

#define BUFSIZE 8192		// zakładamy, że linie będą krótsze niż 8kB

int
main (int argc, char **argv)
{
  int ile_linii = 0;
  char buf[BUFSIZE];		//tablica przechowująca aktualny wiersz
  int i;
  int zr;			//zmienna robocza w case 1
  FILE *in = argc > 1 ? fopen (argv[1], "r") : stdin;
  int decyzja = atoi (argv[2]);	// decyzja = 0->"gdy którykolwiek" 1-> "gdy wszystkie"
  char *str[argc - 3];		// tablice przechowuje wzorce, których będziemy szukać
  if (in == NULL)
    {				//czy podano plik
      fprintf (stderr, "%s: błąd: nie mogę czytać pliku %s\n", argv[0],
	       argv[1]);
      return EXIT_FAILURE;
    }
  if (((atoi (argv[2]) != 0) && (atoi (argv[2]) != 1))
      || (atoi (argv[2]) == NULL))
    {
      fprintf (stderr,
	       "%s: błąd: podano nieprawidłowy parametr sterujący. %s != (0 lub 1)\n",
	       argv[0], argv[2]);
      return EXIT_FAILURE;
    }

  for (i = 0; i < (argc - 3); i++)
    {
      str[i] = argv[i + 3];
    }

  if (str[0] == NULL)
    {				//czy podano chociaż 1 wzorzec
      fprintf (stderr, "%s: błąd: proszę podac napis do wyszukiwania\n",
	       argv[0]);
      return EXIT_FAILURE;
    }

  switch (decyzja)
    {
    case 0:			//pokaz jesli chociaż 1 wzorzec
      while (fgets (buf, BUFSIZE, in) != NULL)
	{			//zaladuj kolejna linie
	  ile_linii++;
	  for (i = 0; i < (argc - 3); i++)
	    if (strstr (buf, str[i]) != NULL)
	      {
		printf ("[%d] %s", ile_linii, buf);
		break;		//znalzlem wzorzec i wyswietlilem wiersz -> przejdz do nastepnego
	      }
	}
      break;
    case 1:			//pokaz tylko gdy wszystkie wzorce
      while (fgets (buf, BUFSIZE, in) != NULL)
	{			//wez kolejny wiersz
	  ile_linii++;		//ktory to kolejny wiersz w pliku
	  zr = 0;		//liczba znalezionych wzorcow
	  for (i = 0; i < (argc - 3); i++)
	    {			//sprawdza wszystkie wzorce po kolei
	      if (strstr (buf, str[i]) != NULL)
		zr++;		//znalazlem jeszcze jeden wzorzec
	    }
	  if (zr == (argc - 3))	//czy znaleziono WSZYSTKIE wzorce
	    printf ("[%d] %s", ile_linii, buf);
	}
      break;
    }
  return EXIT_SUCCESS;

}
