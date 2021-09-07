#include<stdio.h>
int main()
{
	char str[50];
	char* ptr;
	ptr = str;
	scanf("%s", str);
	// printf("str = %s\n", str);
	// printf("ptr = %s\n", ptr);

	// while (*ptr != '\0') ptr++;
	// ptr--;
	// printf("ptr = %s\n", ptr);
	while (*ptr != '\0') {
		// printf("%c", *ptr);
		// ptr++;
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