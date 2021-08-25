// จงเขียนโปรแกรมรับตัวอักษร 1 ชุด แล้วแสดงผลลัพธ์จากหลังมาหน้า
#include <stdio.h>
#include <string.h>

int main ()
{
    char s[100];
    // input
    gets(s);
    // reverse
    strrev(s);
    // output
    printf("%s\n", s);

    return 0;
}