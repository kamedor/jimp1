#include <stdio.h>		// wiadomo po co
#include <stdlib.h>		// qsort
#include <string.h>		// strstr

#define BUFSIZE 8192		// zakładamy, że linie będą krótsze niż 8kB
// -1 domyslny
int
main (int argc, char **argv)
{
  int ile_linii = 0;
  char buf[BUFSIZE];		//tablica przechowująca aktualny wiersz
  int i;
  int zf=0;			//zmienna =1 jeśli nie podano żadnej flagi
  int zr;			//zmienna robocza w case 1
  FILE *in = argc > 1 ? fopen (argv[1], "r") : stdin;
  int decyzja;			// decyzja = 0->"gdy którykolwiek" 1-> "gdy wszystkie"
  if (in == NULL)
    {				//czy podano plik
      fprintf (stderr, "%s: błąd: nie mogę czytać pliku %s\n", argv[0],
	       argv[1]);
      return EXIT_FAILURE;
    }

  if ((strcmp ("-a", argv[2])) == 0)//szuka gdzie są WSZYSTKIE
    {
      decyzja = 1;
    }
  else if ((strcmp ("-v", argv[2])) == 0)//szuka gdzie nie ma ŻADNEGO
    {
      decyzja = 2;
    }
  else if ((strcmp ("-1", argv[2])) == 0)//szuka gdzie nie ma ŻADNEGO
    {
      decyzja = 0;
    }
  else{ //domyslnie szuka chociaż 1
	decyzja = 0;
	if(strcmp("-l",argv[2]) != 0)
	  zf=1;
	
    }

  if(((zr==1)&&(argc<3))||((zr==0)&&(argc<4))){
	 fprintf (stderr, "%s: błąd: proszę podac wzorce do wyszukania\n",argv[0]);
    }

  switch (decyzja)
    {
    case 0:			//pokaz jesli chociaż 1 wzorzec
      while (fgets (buf, BUFSIZE, in) != NULL)
	{			//zaladuj kolejna linie
	  ile_linii++;
	  for (i=(zf==0?3:2) ; i < argc; i++)
	    if (strstr (buf, argv[i]) != NULL)
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
	  for (i=(zf==0?3:2) ; i < argc; i++)
	    {			//sprawdza wszystkie wzorce po kolei
	      if (strstr (buf, argv[i]) != NULL)
		zr++;		//znalazlem jeszcze jeden wzorzec
	    }
	  if (zr == (argc - (argc>3?3:2)))	//czy znaleziono WSZYSTKIE wzorce
	    printf ("[%d] %s", ile_linii, buf);
	}
      break;
    case 2:
      while (fgets (buf, BUFSIZE, in) != NULL)
	{			//wez kolejny wiersz
	  ile_linii++;		//ktory to kolejny wiersz w pliku
	  zr = 0;		//liczba znalezionych wzorcow
	  for (i=(zf==0?3:2) ; i < argc ; i++)
	    {			//sprawdza wszystkie wzorce po kolei
	      if (strstr (buf, argv[i]) != NULL)
		zr++;		//znalazlem jeszcze jeden wzorzec
	    }
	  if (zr == 0)		//czy znaleziono WSZYSTKIE wzorce
	    printf ("[%d] %s", ile_linii, buf);
	}
      break;
    }
  return EXIT_SUCCESS;

}
