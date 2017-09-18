#include<stdio.h>
int main()
{
	int n, i, b[10001] = {0};
	_Bool flag = 0;
	scanf("%d", &n);
	int a[n];
	for(i=0; i<n; i++)
	{
		scanf("%d", a + i);
		b[a[i]]++;
	}
	for(i=0; i<n; i++)
	{
		if(b[a[i]] == 1)
		{
			flag = 1;
			break;
		}
	}
	if(flag)
	{
		printf("%d", a[i]);
	}
	else
	{
		puts("None");
	}
	return 0;
}