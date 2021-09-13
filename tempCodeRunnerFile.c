#include<stdio.h>
int main()
{
    char str[50];
    char *ptr;
    ptr = str;
    scanf("%s", str);

    while (*ptr != '\0') {
        if (*ptr == *(ptr-1))
            ptr++;
        else
        {
            printf("%c", *ptr);
            ptr++;
        }
    }

    return 0;
}