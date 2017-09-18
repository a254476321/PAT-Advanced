#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,k,n,m,s,d,x,y,z,w;
    scanf("%d%d%d%d",&n,&m,&s,&d);
    unsigned short a[n][n],b[n][n],inf,dis[n],cost[n];
    short bf[n];
    _Bool book[n];
    memset(book,0,n);
    memset(b,255,sizeof(cost));
    memset(a,255,sizeof(a));
    inf = a[0][0];
    for(i=0; i<m; i++)
    {
        scanf("%d%d%d%d",&x,&y,&z,&w);
        a[x][y] = z;
        a[y][x] = z;
        b[x][y] = w;
        b[y][x] = w;
    }
    for(i=0; i<n; i++)
    {
        dis[i] = a[s][i];
        cost[i] = b[s][i];
        bf[i] = s;
    }
    book[s]=1;
    for(i=1; i<n; i++)
    {
        m=inf;
        for(j=0; j<n; j++)
        {
            if(!book[j] && dis[j]<m)
            {
                m = dis[j];
                k = j;
            }
        }
        if(m>dis[d])
        {
            break;
        }
        book[k] = 1;
        for(j=0; j<n; j++)
        {
            if(!book[j] && a[k][j] < inf)
            {
                m = dis[k] + a[k][j];
                if(m < dis[j])
                {
                    dis[j] = m;
                    cost[j] = cost[k] + b[k][j];
                    bf[j] = k;
                }
                else if(m == dis[j] && cost[j] > cost[k] + b[k][j])
                {
                    cost[j] = cost[k]+b[k][j];
                    bf[j] = k;
                }
            }
        }
    }
    z = dis[d];
    dis[0] = d;
    x = bf[d];
    i = 1;
    while(x != s)
    {
        dis[i++]=x;
        x=bf[x];
    }
    printf("%d",s);
    for(i--; i>-1; i--)
    {
        printf(" %d",dis[i]);
    }
    printf(" %d %d",z,cost[d]);
	return 0;
}