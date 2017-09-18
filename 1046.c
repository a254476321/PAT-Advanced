#include<stdio.h>

int main()
{
	int n, i, m, x, y, s;
	scanf("%d", &n);
	int a[n + 1];
	a[0] = 0;
	for(i=1; i<=n; i++)
	{
		scanf("%d", a + i);
		a[i] += a[i - 1];
	}
	scanf("%d", &m);
	while(m--)
	{
		scanf("%d%d", &x, &y);
		if(x > y)
		{
			x ^= y;
			y ^= x;
			x ^= y;
		}
		s = a[y - 1] - a[x - 1];
		if(s << 1 > a[n])
		{
			printf("%d\n", a[n] - s);
		}
		else
		{
			printf("%d\n", s);
		}
	}
	return 0;
}