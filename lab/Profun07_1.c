#include <stdio.h>
#include <string.h>

#define max 31

int main()
{
    char str[max][max];
    int i, j,x,y,sizeofstr;

    printf("Input data string:\n");
    for (i = 0;; i++) // input string until input = "."
    {

        scanf(" %[^\n]", &str[i]); // input string str[i]

        if (strcmp(str[i], ".") == 0) // input string until "."
        {
            break;
        }
    }

    FILE *output = fopen("data.txt", "w"); // open file(data.txt) to write


    for (j = 0; j <= i; j++)
    {
        sizeofstr = 0;
        for (int x = 0; str[j][x] != '\0'; x++)
        {
            sizeofstr++;
        }
        fwrite(&str[j], sizeofstr, 1, output);
        fprintf(output, "\n");
    }

    printf("File copied successfully.\n");

    fclose(output);

    return 0;
}