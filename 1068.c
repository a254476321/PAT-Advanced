#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void *a, const void *b)
{
    return *(short*)b - *(short*)a;
}
int main()
{
	int n, m, i, x, j;
	scanf("%d%d", &n, &m);
    short a[n + 1], b[m + 1];
    _Bool c[n + 1][m + 1];
    memset(b, 0, (m + 1) << 1);
    memset(c, 0, sizeof(c));
    for(i=1; i<=n; i++)
    {
        scanf("%d", &x);
        a[i] = x;
    }
    qsort(a + 1, n, 2, cmp);
    for(i=1; i<=n; i++)
    {
        for(j=m; j>=a[i]; j--)
        {
            if(b[j] <= b[j - a[i]] + a[i])
            {
                c[i][j] = 1;
                b[j] = b[j - a[i]] + a[i];
            }
        }
    }
    if(b[m] != m)
    {
        puts("No Solution");
    }
    else
    {
        for(i=n; i>0; i--)
        {
            if(c[i][m] == 1)
            {
                printf("%d", a[i]);
                m -= a[i--];
                break;
            }
        }
        for(; m!=0;i--)
        {
            if(c[i][m] == 1)
            {
                printf(" %d", a[i]);
                m -= a[i];
            }
        }
    }
	return 0;
}