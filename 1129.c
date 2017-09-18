#include<stdio.h>
#include<stdlib.h>
typedef struct rec {
	unsigned short x, num;
} REC;
int cmp(REC *a, REC *b)
{
	return a->num == b->num ? b->x - a->x : a->num - b->num;
}
int cmp1(const void *a, const void *b)
{
	return cmp(*(REC**)b, *(REC**)a);
}
int main()
{
	int n, m, x, i, j;
	_Bool flag;
    scanf("%d%d%d", &n, &m, &x);
	REC a[n + 1], *b[m + 1], *p;
	for(i=0; i<=n; i++)
	{
		a[i].num = 0;
		a[i].x = i;
	}
	for(i=1; i<m; i++)
	{
		b[i] = a;
	}
	a[x].num++;
	b[0] = a + x;
	for(i=1; i<n; i++)
	{
		scanf("%d", &x);
		printf("%d:", x);
		for(j=0; j<m && j<n && b[j]->num!=0; j++)
		{
			printf(" %d", b[j]->x);
		}
		putchar('\n');
		p = a + x;
		flag = cmp(p, b[m - 1]) >= 0 ? 1 : 0;
		p->num++;
		if(!flag)
		{
			if(cmp(p, b[m - 1]) < 0)
			{
				continue;
			}
			b[m - 1] = p;
			qsort(b, m, sizeof(b[0]), cmp1);
		}
		else
		{
			qsort(b, m, sizeof(b[0]), cmp1);
		}
	}
	return 0;
}