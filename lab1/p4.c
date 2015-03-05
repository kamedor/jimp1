#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

        if (argc == 3) {
                int             a = atoi(argv[1]);
                int             b = atoi(argv[2]);
                int             i;

                if (a <= 0 || b <= a || b > 255)
                        return 2;

                printf("Znaki odpowiadające kodom z zakresu %d - %d:\n", a, b);
                for (i = a; i <= b; i++)
                        printf("%d ->  '%c`\n", i, i);

                return 0;
        } else {
                return 1;
        }
}
