#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}
int main()
{
	int n, m, i, x, y;
	_Bool flag = 0;
	scanf("%d%d", &n, &m);
	int a[n];
	for(i=0; i<n; i++)
	{
		scanf("%d", a + i);
	}
	qsort(a, n, 4, cmp);
	y = m >> 1;
	for(i=0; i<n && a[i] <= y; i++)
	{
		x = m - a[i];
		if(bsearch(&x, a + i + 1, n - i - 1, 4, cmp) != NULL)
		{
			printf("%d %d", a[i], x);
			flag = 1;
			break;
		}
	}
	if(!flag)
	{
		puts("No Solution");
	}
	return 0;
}