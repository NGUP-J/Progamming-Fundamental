#include <stdio.h>
int main()
{
    char x[1000];
    scanf("%s", &x);
    int b,a=1;
    for (int i = 0; x[i] != 0; i++)
    {
        b=x[i]-48;
        a*=b;
    }
    printf("%d",a);
    return 0;
}