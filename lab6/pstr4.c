#include <stdio.h>
#include <stdlib.h>		// qsort
#include <string.h>		// strstr

#define BUFSIZE 8192		// zakładamy, że linie będą krótsze niż 8kB

int
main (int argc, char **argv)
{
  int ile_linii = 0;
  char buf[BUFSIZE];		//przechowuje aktualny wiersz
  int i;
  int i_flaga = 3;		//zmienna indeksująca zależna od obecności flagi 
  //if (jest) i_flaga=3 else i_flaga=2
  FILE *in = argc > 1 ? fopen (argv[1], "r") : stdin;
  int decyzja;			//zmienna do switcha; opisana niżej

  //bład pliku
  if (in == NULL)
    {
      fprintf (stderr, "%s: błąd: nie mogę czytać pliku %s\n", argv[0],
	       argv[1]);
      return EXIT_FAILURE;
    }
  //błąd "podano tylko plik
  if (argc <= 2)
    {
      fprintf (stderr, "%s: błąd: nie podano wzorca \n", argv[0]);
      return EXIT_FAILURE;
    }
  //decyzja który tryb uruchomić
  if ((strcmp ("-a", argv[2])) == 0)	//WSZYSTKIE wzorce
    {
      decyzja = 1;
    }
  else if ((strcmp ("-v", argv[2])) == 0)	//ANI JEDNEGO wzorca
    {
      decyzja = 2;
    }
  else if ((strcmp ("-1", argv[2])) == 0)	//CONAJMNIEJ JEDEN wzorzec
    {
      decyzja = 0;
    }
  else				//domyślna flaga -1
    {
      decyzja = 0;
      i_flaga = 2;
    }
  //błąd braku wzorca 
  if ((i_flaga + 1) > argc)
    {
      fprintf (stderr, "%s: błąd: proszę podac wzorce do wyszukania\n",
	       argv[0]);
      return EXIT_FAILURE;
    }

  //wykonanie decyzji zgodnej z flagą
  switch (decyzja)
    {
    case 0:			//flaga "-1" - domyślna                        
      while (fgets (buf, BUFSIZE, in) != NULL)
	{
	  ile_linii++;
	  for (i = i_flaga; i < argc; i++)
	    if (strstr (buf, argv[i]) != NULL)
	      {
		printf ("[%d] %s", ile_linii, buf);
		break;		//znalazłem 1 wzorzec w lini - opuść pętle for
	      }
	}
      break;

    case 1:			//flaga "-a"            
      while (fgets (buf, BUFSIZE, in) != NULL)
	{
	  ile_linii++;
	  for (i = i_flaga; i < argc; i++)
	    {
	      if (strstr (buf, argv[i]) == NULL)
		break;		//nie znalzłem wzorca w linii - opuść for
	      else if (i == (argc - 1))
		printf ("[%d] %s", ile_linii, buf);	/*nie przerwałem wcześniej for,
							 * a to był już ostatni - wyświetl*/
	    }
	}
      break;

    case 2:			//flaga "-v"
      while (fgets (buf, BUFSIZE, in) != NULL)
	{
	  ile_linii++;
	  for (i = i_flaga; i < argc; i++)
	    {
	      if (strstr (buf, argv[i]) != NULL)
		break;		//znalazłem wzorzec w linii - opuść for
	      else if (i == (argc - 1))
		printf ("[%d] %s", ile_linii, buf);	/*nie znalazłem żadnego wzorca
							 * a to był ostatni - wyświetl */
	    }
	}
      break;
    }
  return EXIT_SUCCESS;
}
