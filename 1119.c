#include<stdio.h>
int *pre, *post, *in;
_Bool flag;
void p(short l1, short l2, short r1, short r2)
{
	static short x;
	int i = 0;
	if(l1 == l2)
	{
		in[x++] = pre[l1];
		return;
	}
	if(l1 > l2)
	{
		flag = 1;
		return;
	}
	for(i=r1; i<=r2; i++)
	{
		if(pre[l1 + 1] == post[i])
		{
			break;
		}
	}
	p(l1 + 1, l1 + 1 + i - r1, r1, i);
	in[x++] = pre[l1];
	p(l1 + 2 + i - r1, l2, i + 1, r2 - 1);
}
int main()
{
	int n, i;
	scanf("%d", &n);
	int a[n], b[n], c[n];
	pre = a;
	post = b;
	in = c;
	for(i=0; i<n; i++)
	{
		scanf("%d", a + i);
	}
	for(i=0; i<n; i++)
	{
		scanf("%d", b + i);
	}
	p(0, n-1, 0, n-1);
	if(flag)
	{
		puts("No");
	}
	else
	{
		puts("Yes");
	}
	printf("%d", c[0]);
	for(i=1; i<n; i++)
	{
		printf(" %d", c[i]);
	}
	putchar('\n');
	return 0;
}