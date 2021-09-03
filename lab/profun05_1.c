// จงเขียนโปรแกรมเพื่อรับ String ไปเรื่อยๆ จนกว่าจะเจอคำว่า finished จากนั้นให้แสดงทุกคำที่ป้อนไปในรูปแบบ Capitalization
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define max 100

int main()
{
    int i;
    char str[max][max];
    // input
    for (i = 0;; i++)
    {
        scanf(" %[^\n]", &str[i]);
        if (strcmp(str[i], "finished") == 0)
        {
            break;
        }
    }
    // process
    for (int k = 0; k <= i; k++)
    {
        for (int x = 0; str[k][x] != '\0'; x++)
        {
            switch (str[k][x])
            {
            case 'A' ... 'Z':
            {
                if (str[k][x] == str[k][0])
                {
                    break;
                }
                else
                {
                    /// to lower
                    str[k][x] = str[k][x] + 32;
                }
                break;
            }
            case 'a' ... 'z':
            {
                if (str[k][x] == str[k][0])
                {
                    // to upper
                    str[k][0] = str[k][0] - 32;
                }
                break;
            }
            }
        }
    }
    // output
    for (int j = 0; j < i; j++)
    {
        printf("%s ", str[j]);
    }

    return 0;
}