#include<stdio.h>
int main()
{
	long n;
	int i, j;
	scanf("%ld", &n);
	if(n == 1)
	{
		printf("%ld=%ld", n, n);
	}
	else if((n & 1) == 0)
	{
		printf("%ld=", n);
		n >>= 1;
		i = 0;
		while((n & 1) == 0)
		{
			n >>= 1;
			i++;
		}
		if(i != 0)
		{
			printf("2^%d", i + 1);
		}
		else
		{
			putchar('2');
		}
		i = 3;
	}
	else
	{
		printf("%ld=", n);
		i = 3;
		while(n % i != 0)
		{
			i += 2;
		}
		n /= i;
		j = 0;
		while(n % i == 0)
		{
			n /= i;
			j++;
		}
		if(j != 0)
		{
			printf("%d^%d", i, j + 1);
		}
		else
		{
			printf("%d", i);
		}
		i += 2;
	}
	while(n != 1)
	{
		while(n % i != 0)
		{
			i += 2;
		}
		n /= i;
		j = 0;
		while(n % i == 0)
		{
			n /= i;
			j++;
		}
		if(j != 0)
		{
			printf("*%d^%d", i, j + 1);
		}
		else
		{
			printf("*%d", i);
		}
	}
	return 0;
}