#include<stdio.h>  

int main ()    
{    
    int n,m;    
    printf("Enter a number : ");    
    scanf("%d",&n);
    //loop หา result
    while (n >= 10)
    {
        int sum = 0;
        //loop sum
        while(n>0)    
        {    
            m=n%10;
            sum += m;
            n=n/10;
        }
    n = sum;    
    printf(" -> %d", n);
    }
    return 0;  
}   