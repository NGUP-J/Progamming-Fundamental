#include <stdio.h>
#include <math.h>

int main()
{
    // Get user input
    printf("Input number : ");
    int num;
    do
    {
        scanf("%d", &num);
    }
    while (num < 100 || num > 999);

    int multiply = 1;
    while (num >= 10 || num < 0)
    {
        // Get first digit
        int first_digit = num % 10;
        num = num / 10;
        
        // Get second digit
        int second_digit = num % 10;
        num = num / 10;
        
        // Get third digit
        int third_digit = num % 10;
        num = num / 10;
        
        // Multiply all number
        num = first_digit * second_digit * third_digit;
        printf("%d . %d . %d = %d\n", third_digit, second_digit, first_digit, num);
    }
    return 0;
}