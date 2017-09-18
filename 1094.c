#include<stdio.h>
#include<string.h>
int main()
{
	int n,m,x,y,o,max=0;
    scanf("%d%d",&n,&m);
    short a[n+1],b[n+1];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    while(m--)
    {
        scanf("%d%d",&x,&o);
        while(o--)
        {
            scanf("%d",&y);
            a[y]=x;
        }
    }
    for(x=1;x<n+1;x++)
    {
        o=0;
        y=x;
        while(a[y])
        {
            y=a[y];
            o++;
        }
        b[o]++;
    }
    for(x=0;b[x];x++)
    {
        if(b[x]>max)
        {
            max=b[x];
            o=x;
        }
    }
    printf("%d %d",max,o+1);
	return 0;
}