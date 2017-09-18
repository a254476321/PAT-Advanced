#include<stdio.h>
#include<stdlib.h>
typedef struct gas{
    float pri, dis;
} GAS;
int cmp(const void *a, const void *b)
{
    float x = ((GAS*)a)->dis - ((GAS*)b)->dis;
    return x == 0 ? 0 : (x > 0 ? 1 : -1);
}
int main()
{
    int n, i, cur = 0, min;
    float max, d, p, limits, lim, sum = 0;
    scanf("%f%f%f%d", &max, &d, &p, &n);
    limits = max * p;
    GAS g[n];
    for(i=0; i<n; i++)
    {
        scanf("%f%f", &g[i].pri, &g[i].dis);
    }
    qsort(g, n, sizeof(g[0]), cmp);
    if(g[0].dis != 0)
    {
        puts("The maximum travel distance = 0.00");
        return 0;
    }
    while(1)
    {
        lim = g[cur].dis + limits;
        min = cur;
        for(i=min+1; i<n&&g[i].dis<=lim; i++)
        {
            if(g[i].pri < g[min].pri)
            {
                min = i;
                break;
            }
        }
        if(g[min].pri < g[cur].pri)
        {
            sum += (g[min].dis - g[cur].dis) * g[cur].pri;
        }
        else if(g[cur].dis + limits >= d)
        {
            sum += (d - g[cur].dis) * g[cur].pri;
            break;
        }
        else if(cur == n - 1 || g[cur].dis + limits < g[cur + 1].dis)
        {
            printf("The maximum travel distance = %.2f", g[cur].dis + limits);
            return 0;
        }
        else
        {
            min = cur + 1;
            for(i=min+1; i<n&&g[i].dis<=lim; i++)
            {
                if(g[i].pri < g[min].pri)
                {
                    min = i;
                }
            }
            sum += g[cur].pri * limits - (limits + g[cur].dis 
            - g[min].dis) * g[min].pri;
        }
        cur = min;
    }
    printf("%.2f", sum / p);
    return 0;
}