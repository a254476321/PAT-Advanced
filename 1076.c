#include<stdio.h>
#include<string.h>
#include<malloc.h>
int main()
{
	short m, n, i, j, k, q, p, t, level, cur;
    scanf("%hd%hd", &n, &m);
    short *a[n + 1], num[n + 1], queue[n];
    _Bool v[n + 1];
    memset(num, 0, (n + 1) << 1);
    for(i=1; i<=n; i++)
    {
        a[i] = (short*)malloc(n << 1);
    }
    for(i=1; i<=n; i++)
    {
        scanf("%hd", &j);
        while(j--)
        {
            scanf("%hd", &k);
            a[k][num[k]++] = i;
        }
    }
    scanf("%hd", &q);
    while(q--)
    {
        scanf("%hd", &p);
        memset(v, 0, n + 1);
        queue[0] = p;
        v[p] = 1;
        level = cur = 0;
        t = k = 1;
        while(cur < k && level < m)
        {
            i = queue[cur];
            for(j=0; j<num[i]; j++)
            {
                if(v[a[i][j]] == 0)
                {
                    queue[k++] = a[i][j];
                    v[a[i][j]] = 1;
                }
            }
            cur++;
            if(cur == t)
            {
                t = k;
                level++;
            }
        }
        printf("%d\n", k - 1);
    }
    for(i=1; i<=n; i++)
    {
        free(a[i]);
    }
	return 0;
}