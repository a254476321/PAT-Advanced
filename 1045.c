#include<stdio.h>
#include<string.h>
int main()
{
	int n, i, j, m, x, y, max = 0;
    scanf("%d",&n);
    short a[n+1];
    memset(a, 0, sizeof(a));
    scanf("%d", &m);
    for(i=1; i<=m; i++)
    {
        scanf("%d", &x);
        a[x] = i;
    }
    short b[m+1];
    memset(b, 0, sizeof(b));
    scanf("%d", &y);
    while(y--)
    {
        scanf("%d", &x);
        if(a[x] == 0)
        {
            continue;
        }
        x = a[x];
        for(j=1; j<x; j++)
        {
            if(b[j] > b[x])
            {
                b[x] = b[j];
            }
        }
        b[x]++;
    }
    for(i=1; i<=m; i++)
    {
        if(max < b[i])
        {
            max = b[i];
        }
    }
    printf("%d", max);
	return 0;
}