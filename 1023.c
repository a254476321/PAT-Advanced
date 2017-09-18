#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void *a, const void *b)
{
	return *(char*)a - *(char*)b;
}
int main()
{
	short n, n2;
	unsigned long x;
	char a[21], b[22], c[22];
	gets(a);
	n = strlen(a);
	if(n < 19)
	{
		sscanf(a, "%lu", &x);
		sprintf(b, "%lu", x << 1);
	}
	else
	{
		int y;
		sscanf(a, "%18lu%d", &x, &y);
		x <<= 1;
		y <<= 1;
		if(y > 100)
		{
			y -= 100;
			x++;
		}
		else if(n == 19 && y > 10)
		{
			y -= 10;
			x++;
		}
		sprintf(b, "%lu%d", x, y);
	}
	n2 = strlen(b);
	memcpy(c, b, n2 + 1);
	qsort(a, n, 1, cmp);
	qsort(b, n2, 1, cmp);
	if(strcmp(a, b) == 0)
	{
		puts("Yes");
	}
	else
	{
		puts("No");
	}
	puts(c);
	return 0;
}