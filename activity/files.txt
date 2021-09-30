#include <string.h>
#include <stdio.h>
int main()
{
    int i;
    struct player
    {
        char name[50];
        int level;
        int score;
    };
    struct player p[10];
    for (i = 0; i < 5; i++)
    {
        strcpy(p[i].name, "Anonymous");
        p[i].level = i;
        p[i].score = i * 100;
    }
    for (i = 0; i < 5; i++)
    {
        printf("name : %s\t", p[i].name);
        printf("level : %d\t", p[i].level);
        printf("score : %d\n", p[i].score);
    }
    // เปิดไฟล์
    FILE *output = fopen("player.txt","w");

        for (i = 0; i < 5; i++)
    {
        fprintf(output,"name : %s\t", p[i].name);
        fprintf(output,"level : %d\t", p[i].level);
        fprintf(output,"score : %d\n", p[i].score);
    }
    // fwrite(&p,sizeof(p),1,output);


    fclose(output);



    return 0;
}