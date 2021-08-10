#include <stdio.h>

const int INPUT_SIZE = 3;

int main()
{
    // Get user input
    printf("Input number : ");
    int num[INPUT_SIZE];

    int tmp = 0;
    scanf("%i", &tmp);

    for (int i = 0; i < INPUT_SIZE; i++)
    {
        num[2 - i] = tmp % 10;
        tmp /= 10;
    }

    int multiply = 100;
    while (multiply >= 10 || multiply < 0)
    {

        // Get first digit
        int first_digit = num[2];

        // Get second digit
        int second_digit = num[1];

        // Get third digit
        int third_digit = num[0];

        // Multiply all number
        multiply = first_digit * second_digit * third_digit;

        printf("%i . %i . %i = %i\n", third_digit, second_digit, first_digit, multiply);

        // Initialize multiply to num
        int tmp1 = multiply;

        for (int i = 0; i < INPUT_SIZE; i++)
        {
            num[2 - i] = tmp1 % 10;
            tmp1 /= 10;
        }

    }

    return 0;
}