#include <stdio.h>

#define max 1

int main()
{
    char ch, file_1[max], file_2[max];
    FILE *input, *output;
    printf("Input : ");
    gets(file_1);

    input = fopen(file_1, "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    printf("Output : ");
    gets(file_2);

    output = fopen(file_2, "w");

    while (fread(file_1, sizeof(char), 1, input))
        fwrite(file_1, sizeof(char), 1, fp2);
    printf("File copied successfully.\n");

    fclose(fp1);
    fclose(fp2);

    return 0;
}