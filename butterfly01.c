#include <stdio.h>

int main ()
{
    int w,h,n,x;
    printf("Enter Number : ");
    scanf("%d", &h);

    //loop upper
    for (w = 1;w <= h - 1; w++)
    {
        // wing upper right
        for (n = 1;n <= w; n++)
        {
            putchar('*');
        }
        // blank
        for (x = 1;x <= 2 * (h - w); x++)
        {
            putchar(' ');
        }
        putchar('\b');
        // wing upper left
        for (n = w;n >= 1; n--)
        {
            putchar('*');
        }
        putchar('\n');
    }

    //loop down
    for (w = h;w >=1; w--)
    {
        // wing lower right
        for (n = 1;n <= w; n++)
        {
            putchar('*');
        }
        // blank
        for (x = 1;x <= 2 * (h - w); x++)
        {
            putchar(' ');
        }
    putchar('\b');
        // wing lower left
        for (n = w;n >= 1; n--)
        {
            putchar('*');
        }
    putchar('\n');
    }
    return 0;
}