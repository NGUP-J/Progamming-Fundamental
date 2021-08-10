#include <stdio.h>
int main()
{
    float Weight,Height,BMI;
    printf("Enter Weight : ");
    scanf("%f", &Weight);
    printf("Enter Height : ");
    scanf("%f", &Height);
    BMI = Weight/((Height*Height)*0.0001);
    if (BMI>=30)
    {
        printf("Obesity");
    }
    else if (BMI>=25)
    {
        printf("Overweight");
    }
    else if (BMI>=18.5)
    {
        printf("Normal");
    }
    else if (BMI<18.5)
    {
        printf("Underweight");
    }
    return 0;
}