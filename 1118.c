#include<stdio.h>
short search(short x, short a[])
{
	return a[x] == 0 ? x : (a[x] = search(a[x], a));
}
_Bool combine(int x, int y, short a[])
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
	int n, m, s = 0, i, x, y;
	short a[10001] = {0};
	_Bool b[10001] = {0};
	scanf("%d", &n);
	int f[n];
	for(i=0; i<n; i++)
	{
		scanf("%d%d", &m, &x);
		f[i] = x;
		while(--m)
		{
			scanf("%d", &y);
			if(combine(x, y, a))
			{
				s++;
			}
		}
	}
	y = 0;
	for(i=0; i<n; i++)
	{
		x = search(f[i], a);
		if(b[x] == 0)
		{
			b[x] = 1;
			y++;
		}
	}
	printf("%d %d\n", y, y + s);
	scanf("%d", &m);
	while(m--)
	{
		scanf("%d%d", &x, &y);
		if(search(x, a) == search(y, a))
		{
			puts("Yes");
		}
		else
		{
			puts("No");
		}
	}
	return 0;
}