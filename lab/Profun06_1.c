#include <stdio.h>

int main()
{
    char ch,file_1[40],file_2[40];
    FILE *input,*output;
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

    while ((ch = fgetc(input)) != EOF)
        fputc(ch,output);
    printf("File copied successfully.\n");

    fclose(input);
    fclose(output);

    return 0;
}
// 