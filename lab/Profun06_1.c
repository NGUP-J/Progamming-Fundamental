#include <stdio.h>

int main()
{
    char ch,file_1[40],file_2[40];
    FILE *fp1,*fp2;
    printf("Input : ");
    gets(file_1);

    fp1 = fopen(file_1, "r");

    printf("Output : ");
    gets(file_2);

    fp2 = fopen(file_2, "w");

    while ((ch = fgetc(fp1)) != EOF)
        fputc(ch,fp2);
    printf("File copied successfully.\n");

    fclose(fp1);
    fclose(fp2);

    return 0;
}