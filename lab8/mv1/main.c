#include "parser.h"

#include <ctype.h>

int main(int argc, char **argv){
  int l_plikow = (isdigit(argv[1])==0) ? 1: argv[1];
  int i;
  char *plik[l_plikow];
  for (i=0;i<l_plikow;i++){
    *plik[i]= argv[2+i];
    analizatorSkladni(plik[i]);
  }
  return 0;
}
