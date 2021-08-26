#include <stdio.h>

int main ()
{
   char s[1000], r[1000];
   int x, e, n = 0;
   // input string
   printf("Input a string : ");
   gets(s);
   // reverse string
   while (s[n] != '\0')
      n++;

   e = n - 1;

   for (x = 0; x < n; x++) {
      r[x] = s[e];
      e--;
   }

   r[x] = '\0';
   // output reverse string
   printf("%s\n", r);

   return 0;
}