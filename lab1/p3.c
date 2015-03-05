#include <stdio.h>

int main()
{
        int             i;

        printf("Kody dziesiętne wielkich liter:\n");
        for (i = 'A'; i <= 'Z'; i++)
                printf("%c - %d\n", i, i);

        return 0;
}
