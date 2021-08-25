#include <stdio.h>

int main()

{

    int n, reversedInteger = 0, remainder, originalInteger;

    printf("Enter an integer: ");

    scanf("%d", &n);

    originalInteger = n; //121

    // reversed integer is stored in variable (#1)

    while (n != 0)

    {

        remainder = n % 10; // 121/10 = 1  12/10 = 2 / 1/10 = 0 

        reversedInteger = reversedInteger * 10 + remainder; // 1 * 10+1 = 11  / 11 * 10+2 = 132 / 132*10+0 = 1320

        n /= 10; //(#2) 121/10 = 12 / 12/10 = 1 / 1/10 = 0
    }
    printf("%d\n", reversedInteger);
    // palindrome if orignalInteger and reversedInteger are equal (#3)

    if (originalInteger == reversedInteger)

        printf("%d is a palindrome.", originalInteger);

    else

        printf("%d is not a palindrome.", originalInteger);

    return 0;
}