#include<stdio.h>
#include<string.h>
int p1(int x, const int a[],int b[])
{
	if(x == 0)
	{
		return 1;
	}
	else if(b[x] != 0)
	{
		return b[x] + 1;
	}
	else
	{
		return (b[x] = p1(a[x], a, b)) + 1;
	}
}
int main()
{
	int n, i, j, k;
	double p, r, sum = 0, s;
    scanf("%d%lf%lf", &n, &p, &r);
	r = 1 + r / 100;
	int a[n], b[n], c[n], d[n];
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	memset(d, 0, sizeof(d));
	for(i=0; i<n; i++)
	{
		scanf("%d", &j);
		if(j == 0)
		{
			scanf("%d", b + i);
		}
		else
		{
			while(j--)
			{
				scanf("%d", &k);
				a[k] = i;
			}
		}
	}
	for(i=0; i<n; i++)
	{
		if(b[i] != 0)
		{
			j = p1(i, a, c);
			d[j - 1] += b[i]; 
		}
	}
	k = n - 1;
	while(d[k] == 0)
	{
		k--;
	}
	s = p;
	for(i=0; i<=k; i++)
	{
		if(d[i] != 0)
		{
			sum += d[i] * s;
		}
		s *= r;
	}
	printf("%.1lf", sum);
	return 0;
}