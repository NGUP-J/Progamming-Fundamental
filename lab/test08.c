#include <stdio.h>

int main()
{
    FILE *fp;
    int a, b, c, suma = 0, sumb = 0, sumc = 0;
    fp = fopen("mytestfile.txt", "r");
    while (!feof(fp))
    {
        a = 0;
        b = 0;
        c = 0;
        fscanf(fp, "%d %d %d", &a, &b, &c);
        suma += a;
        sumb += b;
        sumc += c;
    }
    printf("%d %d %d\n", suma, sumb, sumc);
    fclose(fp);
    return 0;
}