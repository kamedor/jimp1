#include <stdio.h>

int main()
{
        int             i = 0;
        int             j = 1;

        printf("i=%d\n", i);
        printf("j=%d\n", j);
        printf("i-j=%d\n", i - j);
        i = j + 1;
        printf("j+1=%d\n", i);
        j -= 3;
        printf("j-3=%d\n", j);
        printf("j=j-3\n");
        printf("j=%d\n", j);
        printf("%d+%d=%d\n", i, j, i + j);
        printf("%d*%d=%d\n", i, j, i * j);

        return 0;
}
