#include <stdio.h>
#include <string.h>
#include <ctype.h>

int num(char *tmp, char c)
{
    for (int i = 0; i < strlen(tmp); ++i)
    {
        if (c == tmp[i])
        {
            return i;
        }
    }
    return -1;
}

void convert(char *str)
{
    char a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    char *m[] =
        {
            ".-",
            "-...",
            "-.-.",
            "-..",
            ".",
            "..-.",
            "--.",
            "....",
            "..",
            ".---",
            "-.-",
            ".-..",
            "--",
            "-.",
            "---",
            ".--.",
            "--.-",
            ".-.",
            "...",
            "-",
            "..-",
            "...-",
            ".--",
            "-..-",
            "-.--",
            "--..",
            "-----",
            ".----",
            "..---",
            "...--",
            "....-",
            ".....",
            "-....",
            "--...",
            "---..",
            "----."};
    for (int i = 0; i < strlen(str); ++i)
    {
        int pos = num(a, (char)toupper(str[i]));
        if (pos != -1)
        {
            printf("%s ", m[pos]);
        }
    }
}

int main()
{
    char str[20];

    printf("Enter str to Morse Code : ");
    scanf("%s", str);
    convert(str);

    return 0;
}