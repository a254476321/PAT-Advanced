#include<stdio.h>
#include<string.h>
short pow1(short x, short n)
{
    short sum = x;
    while(--n)
    {
        sum *= x;
    }
    return sum;
}
int k;
short *a, *f, *power, sum2, k2;
_Bool dfs(short N, short cur)
{
    if(cur == k)
    {
        if(N == 0)
        {
            short sum = 0;
            for(short i=0; i<k; i++)
            {
                sum += a[i];
            }
            if(sum >= sum2)
            {
                sum2 = sum;
                memcpy(f, a, k << 1);
            }
            return 1;
        }
        else
        {
            return 0;
        }
    }
    for(short i=cur<1?1:a[cur-1]; i<=k2; i++)
    {
        if(N >= power[i])
        {
            a[cur] = i;
            dfs(N - power[i], cur + 1);
        }
        else
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
	int n, p, i;
    short po[21];
    scanf("%d%d%d", &n, &k, &p);
    po[1] = 1;
    for(i=2; po[i-1]<n; i++)
    {
        po[i] = pow1(i, p);
    }
    k2 = i;
    power = po;
    short num[k], fin[k];
    f = fin;
    a = num;
    dfs(n, 0);
    if(sum2 != 0)
    {
        printf("%d = %d^%d", n, fin[k - 1], p);
        for(i=k-2; i>=0; i--)
        {
            printf(" + %d^%d", fin[i], p);
        }
    }
    else
    {
        puts("Impossible");
    }
	return 0;
}