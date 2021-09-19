#include <stdio.h>
#include <string.h>

#define max 30

int main()
{
    char str[max];
    int i;
    FILE *output = fopen("data.txt", "a");

    printf("Input data string :\n");

    do
    {
        // input string
        gets(str);
        // put to data.txt
        fputs(str, output);
        fprintf(output, "\n");
    } while (strcmp(str, ".") != 0);

    // for (;;)
    // {
    //     gets(str);
    //     fputs(str, output);
    //     fprintf(output, "\n");

    //     if (strcmp(str, ".") == 0) // input string until "."
    //     {
    //         break;
    //     }
    // }

    printf("File copied successfully.\n");

    fclose(output);

    return 0;
}