// จงเขียนโปรแกรมเพื่อรับ String ไปเรื่อยๆ จนกว่าจะเจอคำว่า finished จากนั้นให้แสดงทุกคำที่ป้อนไปในรูปแบบ Capitalization
#include <stdio.h>
#include <string.h>
#define max 100

int main ()
{
    int i;
    char str[max][max];
    // input
    for (i = 0;;i++){
        scanf(" %[^\n]", &str[i]);
        if (str[i] == "finished"){
            break;
        }
    }
    // output
    for (int j = 0;j < i;j++){
        printf("%s ", str[j]);
    }

    return 0;
}