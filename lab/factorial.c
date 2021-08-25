#include <stdio.h>

int main ()
{
    int c, n, f = 1;

    printf("Enter a number to calculate its factorial\n");
    scanf("%d", &n);

    for (c = 1; c <= n; c++)
    {
        f *= c;
    }

    printf("Factorial of %d = %d", n, f);
    return 0;
}