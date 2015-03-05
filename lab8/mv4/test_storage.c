#include <stdio.h>
#include "storage.h"

int main(int argc, char **argv){
	char *funame="funkcja";
	char *plik="jakisplik";
	int ln= 17;
	store_add_def(funame,ln,plik);
	print_def();
	return 0;
}