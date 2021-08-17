#include <stdio.h>

int main ()
{
    int num, rem, i;
    for (num = 1;num <= 10000;num++)
    {
        int sum = 0;
        for (i = 1; i < num; i++)
        {
            rem = num % i;
            if (rem == 0)
            {
                sum += i;
            }
        }
        if (sum == num)
        {
            printf(" %d ", sum);
        }
 
    }
    return 0;
}