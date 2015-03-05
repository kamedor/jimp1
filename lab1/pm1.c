#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	if(argc>3)
	{	
	
		int a=0;
		int b=argc;
		int i;
	
		for(i=1;i<b;i++)
			{
			a = a + atoi(argv[i]);
			}
		printf("Suma to %d \n",a);
	
	}
	else
	{
		printf("podaj conajmniej 3 liczby\n");
		return 1; 
	}

	return 0;
}
