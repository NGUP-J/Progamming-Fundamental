#include <stdio.h>
#include <string.h>

#define max 31

int main()
{
    char str[max][max];
    int i, j, k;

    // input str
    printf("Input data string :\n");
    for (i = 0;; i++)
    {
        
        scanf(" %[^\n]", &str[i]);
        
        if (strcmp(str[i], ".") == 0)  // input string until "."
        {
            break;
        }
    }

    FILE *output = fopen("data.txt", "w"); // open file(data.txt) to write

    for (k = 0; k <= i; k++)
    {

        fputs(str[k], output);
        fprintf(output, "\n");
    }

    printf("File copied successfully.\n");

    fclose(output);

    return 0;
}