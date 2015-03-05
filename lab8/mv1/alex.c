//analizator leksykalny
#include "alex.h"

#include <ctype.h> // (?)
// (?) static
static int ln=0;
static char ident[256];
static FILE *ci=NULL;

void  alex_init4file( FILE *in ) {
  ln=0;
  ci=in;
}

lexem_t alex_nextLexem(void) {
  int c;
  while( (c= fgetc(ci)) != EOF ) {
    if( isspace( c ) )    //białe znaki
      continue;
    else if(c == '\n' )   //koniec lini -> ln++
      ln++;
    else if(c == '(' )    //kolejne typy wyliczeniowe
      return OPEPAR;
    else if(c == ')' )
      return CLOPAR;
    else if(c == '{' )
      return OPEBRA;
    else if(c == '}' )
      return CLOBRA;
    else if( isalpha(c) ){//litery
      int i= 1;
      ident[0]= c;
      while(isalnum( c=fgetc(ci) ) )//litery lub liczby
        ident[i++]= c;
      ident[i]= '\0';
      return isKeyword(ident) ? OTHER : IDENT;
    } else if( c=='"') {
      int cp=c;
      while( (c=fgetc(ci)) != EOF && c =='\\') {
        cp=c;
      }
      return c==EOF ? EOFILE : OTHER;
    } else if(c== '/'){
      /*może być komentarz */
      // (?)
    } if ( isdigit( c ) || c=='.') {
      /*liczba*/
      //(?)
    } else {
      return OTHER;
    }
  }
return EOFILE;
}

char* alex_ident( void) {
  return ident;
}

int alex_getLN() {
  return ln;
}
