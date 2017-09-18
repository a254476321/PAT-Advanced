#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n, m, k, i, j;
    long *a, *b;
    scanf("%d", &n);
    a = (long *)malloc((n + 1) * sizeof(long));
    for(i=0; i<n; i++)
    {
        scanf("%ld",a + i);
    }
    scanf("%d", &m);
    b = (long *)malloc((m + 1) * sizeof(long));
    for(i=0; i<m; i++)
    {
        scanf("%ld",b + i);
    }
    if(a[(n - 1) >> 1] == b[(m - 1) >> 1])
    {
        printf("%ld", a[(n - 1) >> 1]);
        return 0;
    }
    a[n] = b[m] = a[n - 1] > b[m - 1] ? a[n - 1] + 1 : b[m - 1] + 1;
    i = j = k = 0;
    n = (n + m - 1) >> 1;
    while(k < n)
    {
        if(a[i] < b[j])
        {
            k++;
            i++;
        }
        else
        {
            k++;
            j++;
        }
    }
    if(a[i] < b[j])
    {
        printf("%ld", a[i]);
    }
    else
    {
        printf("%ld", b[j]);
    }
    free(a);
    free(b);
	return 0;
}