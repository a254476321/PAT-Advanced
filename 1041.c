#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}
int main()
{
	int n, i, start, end, mid;
	scanf("%d", &n);
	int a[n], b[n];
	_Bool flag = 0;
	for(i=0; i<n; i++)
	{
		scanf("%d", a+i);
	}
	memcpy(b, a, sizeof(a));
	qsort(b, n, sizeof(b[0]), cmp);
	for(i=0; i<n; i++)
	{
		start = 0;
		end = n - 1;
		while(start <= end)
		{
			mid = (start + end) >> 1;
			if(b[mid] < a[i])
			{
				start = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}
		if(start == n - 1 || b[start] != b[start + 1])
		{
			flag = 1;
			break;
		}
	}
	if(flag)
	{
		printf("%d", b[start]);
	}
	else
	{
		puts("None");
	}
	return 0;
}