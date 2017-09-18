#include<stdio.h>
int main()
{
    int n, m, m2, i, k = 0, min, low, high, mid;
	scanf("%d%d", &n, &m);
    int a[n + 1], f[n][2];
    a[0] = 0;
    for(i=1; i<=n; i++)
    {
        scanf("%d", a + i);
        a[i] += a[i - 1];
    }
    if(m > a[n])
    {
        return 0;
    }
    else if(m == a[n])
    {
        printf("1-%d", n);
        return 0;
    }
    low = 1;
    high = n;
    while(low <= high)
    {
        mid = (low + high) >> 1;
        if(a[mid] < m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    min = a[low];
    f[k][0] = 1;
    f[k++][1] = low;
    for(i=1; i<n; i++)
    {
        m2 = m + a[i];
        if(m2 > a[n])
        {
            break;
        }
        high = n;
        while(low <= high)
        {
            mid = (low + high) >> 1;
            if(a[mid] < m2)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        m2 = min + a[i];
        if(a[low] < m2)
        {
            min = a[low] - a[i];
            k = 0;
            f[k][0] = i + 1;
            f[k++][1] = low;
        }
        else if(a[low] == m2)
        {
            f[k][0] = i + 1;
            f[k++][1] = low;
        }
    }
    for(i=0; i<k; i++)
    {
        printf("%d-%d\n", f[i][0], f[i][1]);
    }
	return 0;
}