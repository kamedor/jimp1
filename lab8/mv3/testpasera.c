#include "parser.h"
#include "alex.h"
#include	"fun_stack.h"


int main(int argc, char **argv){
	int i;
	for ( i= 0; i < argc; i++)
		analizatorSkladni (argv[i+1]);
	return 0;
}