#include<stdio.h>

int isPrime(int);
int main() 
{
	int x;
	scanf("%d", &x);
	if (isPrime(x) == 1)
		printf("Prime number");
	else
		printf("Not Prime number");
	return 0;
}
int isPrime(int a)
{
	int n;

	for (n = 2;n <= a - 1; n++){
		if ( a % n == 0 )
		return 0;
	}
	return 1;
}