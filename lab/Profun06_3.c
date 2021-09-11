#include <stdio.h>

int main()
{
    char tmp[10];
    printf("Input: ");
    scanf("%s", tmp);

    FILE *input = fopen(tmp, "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    printf("Output: ");
    scanf("%s", tmp);

    FILE *output = fopen(tmp, "w");

    char file_1[1];
    while (fread(file_1, sizeof(char), 1, input))
    {
        fwrite(file_1, sizeof(char), 1, output);
    }
    printf("File copied successfully.\n");

    fclose(input);
    fclose(output);

    return 0;
}