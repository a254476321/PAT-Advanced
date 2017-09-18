#include <stdio.h>
int main()
{
    int n, m, i, k, x, max = 0;
    short fa[101] = {0}, level[100] = {0}, leaf[101] = {0};
    _Bool s[101] = {0};
    scanf("%d%d", &n, &m);
    if(m == 0)
    {
        printf("%d\n", n);
        return 0;
    }
    while(m--)
    {
        scanf("%d%d", &x, &k);
        s[x] = 1;
        while(k--)
        {
            scanf("%d", &n);
            fa[n] = x;
            leaf[n] = 1;
        }
    }
    for(i=0; i<101; i++)
    {
        if(leaf[i] & !s[i])
        {
            x = i;
            k = 0;
            while(fa[x])
            {
                x = fa[x];
                k++;
            }
            level[k]++;
            if(k > max)
            {
                max = k;
            }
        }
    }
    printf("0");
    for(i=1; i<=max; i++)
    {
        printf(" %d", level[i]);
    }
    return 0;
}