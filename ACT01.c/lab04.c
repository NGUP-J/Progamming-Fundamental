#include <stdio.h>
#include <math.h>

int main()
{
    double x, y, z;
    // input
    printf("input number : ");
    scanf("%lf %lf %lf", &x, &y, &z);
    if (x + y <= z || x + z <= y || y + z <= x)
        printf("0");
    else
    {
        double S = (x + y + z) * .5;
        double B = S * (S - x) * (S - y) * (S - z);
        double A = pow(B, 0.5);
        if (A > 0)
            printf("%lf\n", A);
        else
            printf("0");
    }

    return 0;
}