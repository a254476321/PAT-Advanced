#include<stdio.h>
#include<string.h>
int main()
{
    int n, m, v, w, x, y, z, i, j, k1 = 0, k2 = 0;
    scanf("%d%d", &n, &m);
    int e[n][n], t[n][n], dis[n], time[n], inf;
    short f1[n], f2[n], s1[n], s2[n];
    _Bool book[n];
    memset(e, 6, sizeof(e));
    memset(t, 6, sizeof(t));
    inf = e[0][0];
    while(m--)
    {
        scanf("%d%d%d%d%d", &v, &w, &x, &y, &z);
        e[v][w] = y;
        t[v][w] = z;
        if(x != 1)
        {
            e[w][v] = y;
            t[w][v] = z;
        }
    }
    scanf("%d%d", &x, &y);
    e[x][x] = t[x][x] = 0;
    for(i=0; i<n; i++)
    {
        f1[i] = f2[i] = x;
    }
    memset(book, 0, n);
    book[x] = 1;
    memcpy(dis, e + x, n << 2);
    memcpy(time, t + x, n << 2);
    for(i=1; i<n; i++)
    {
        v = inf;
        for(j=0; j<n; j++)
        {
            if(!book[j] && dis[j] < v)
            {
                v = dis[j];
                w = j;
            }
        }
        if(v > dis[y])
        {
            break;
        }
        book[w] = 1;
        for(j=0; j<n; j++)
        {
            if(!book[j] && e[w][j] < inf)
            {
                z = dis[w] + e[w][j];
                if(dis[j] > z)
                {
                    f1[j] = w;
                    time[j] = time[w] + t[w][j];
                    dis[j] = z;
                }
                else if(dis[j] == z && time[j] > time[w] + t[w][j])
                {
                    time[j] = time[w] + t[w][j];
                    f1[j] = w;
                }
            }
        }
    }
    m = dis[y];
    for(j=y; j!=x; j=f1[j])
    {
        s1[k1++] = j;
    }
    memset(book, 0, n);
    book[x] = 1;
    memset(dis, 0, n << 2);
    memcpy(time, t + x, n << 2);
    for(i=1; i<n; i++)
    {
        v = inf;
        for(j=0; j<n; j++)
        {
            if(!book[j] && time[j] < v)
            {
                v = time[j];
                w = j;
            }
        }
        if(v > time[y])
        {
            break;
        }
        book[w] = 1;
        for(j=0; j<n; j++)
        {
            if(!book[j] && t[w][j] < inf)
            {
                z = time[w] + t[w][j];
                if(time[j] > z)
                {
                    f2[j] = w;
                    dis[j] = dis[w] + 1;
                    time[j] = z;
                }
                else if(time[j] == z && dis[j] > dis[w] + 1)
                {
                    dis[j] = dis[w] + 1;
                    f2[j] = w;
                }
            }
        }
    }
    for(j=y; j!=x; j=f2[j])
    {
        s2[k2++] = j;
    }
    if(memcmp(s1, s2, k1 << 1) != 0)
    {
        printf("Distance = %d: %d", m, x);
        for(k1--;k1>=0;k1--)
        {
            printf(" -> %d", s1[k1]);
        }
        putchar('\n');
        printf("Time = %d: %d", time[y], x);
        for(k2--;k2>=0;k2--)
        {
            printf(" -> %d", s2[k2]);
        }
    }
    else
    {
        printf("Distance = %d; Time = %d: %d", m, time[y], x);
        for(k1--;k1>=0;k1--)
        {
            printf(" -> %d", s1[k1]);
        }
    }
	return 0;
}