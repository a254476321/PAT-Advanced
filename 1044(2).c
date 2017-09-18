#include<stdio.h>
int main()
{
    int n, m, i, j, k = 0, min, sum;
	scanf("%d%d", &n, &m);
    int a[n + 1], f[n][2];
    a[0] = sum = 0;
    for(i=1; i<=n; i++)
    {
        scanf("%d", a + i);
        sum += a[i];
        if(sum >= m)
        {
            j = i;
            min = sum;
            break;
        }
    }
    for(i++; i<=n; i++)
    {
        scanf("%d", a + i);
        sum += a[i];
    }
    if(m > sum)
    {
        return 0;
    }
    else if(m == sum)
    {
        printf("1-%d", n);
        return 0;
    }
    f[k][0] = 1;
    f[k++][1] = j;
    sum = min;
    for(i=1; i<n; i++)
    {
        sum -= a[i];
        while(j < n && sum < m)
        {
            sum += a[++j];
        }
        if(sum < m)
        {
            break;
        }
        if(sum < min)
        {
            min = sum;
            k = 0;
            f[k][0] = i + 1;
            f[k++][1] = j;
        }
        else if(sum == min)
        {
            f[k][0] = i + 1;
            f[k++][1] = j;
        }
    }
    for(i=0; i<k; i++)
    {
        printf("%d-%d\n", f[i][0], f[i][1]);
    }
	return 0;
}