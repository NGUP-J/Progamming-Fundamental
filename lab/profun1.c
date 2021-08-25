#include <stdio.h>

const int INPUT_SIZE = 3;

int main()
{
    // Get user input
    printf("Input number : ");
    int num[INPUT_SIZE];
    int tmp = 0;
    do
    {
        scanf("%d", &tmp);
    }
    while (tmp < 100 || tmp > 999);

    for (int i = 0; i < INPUT_SIZE; i++)
    {
        num[2 - i] = tmp % 10;
        tmp /= 10;
    }

    int multiply = 100;
    while (multiply >= 10 || multiply < 0)
    {

        // Multiply all number
        multiply = num[2] * num[1] * num[0];

        printf("%i . %i . %i = %i\n", num[2], num[1], num[0], multiply);

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