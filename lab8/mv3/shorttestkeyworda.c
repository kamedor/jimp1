#include <stdio.h>
#include "alex.h"

int main (){

char *s[3];
s[0] = "printf";
s[1] = "include";
s[2] = "Kamil";

int i;

for (i=0; i<3; i++)
  printf("%d \n", isKeyworda(s[i]));



  return 0;
}
