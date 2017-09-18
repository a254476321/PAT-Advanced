#include<stdio.h>
#include<string.h>
short search(short x, short a[])
{
	return a[x] == 0 ? x : (a[x] = search(a[x], a));
}
_Bool combine(short x, short y, short a[])
{
	x = search(x, a);
	y = search(y, a);
	if(x == y)
	{
		return 0;
	}
	else
	{
		a[y] = x;
		return 1;
	}
}
int main()
{
	int n, m, i, x, y;
	scanf("%d%d", &n, &m);
	short a[n + 1], b[n + 1];
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	i = 0;
	while(m--)
	{
		scanf("%d%d", &x, &y);
		a[x]++;
		a[y]++;
		if(combine(x, y, b))
		{
			i++;
		}
	}
	if(i != n - 1)
	{
		x = 3;
	}
	else
	{
		x = a[1] & 1;
	}
	printf("%d", a[1]);
	for(i=2; i<=n; i++)
	{
		printf(" %d", a[i]);
		x += a[i] & 1;
	}
	if(x == 0)
	{
		puts("\nEulerian");
	}
	else if(x == 2)
	{
		puts("\nSemi-Eulerian");
	}
	else
	{
		puts("\nNon-Eulerian");
	}
	return 0;
}