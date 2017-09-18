#include<stdio.h>
#include<string.h>
short search(short x,short a[])
{
    if(a[x]==x) return x;
    else 
    {
        a[x]=search(a[x],a);
        return a[x];
    }
}
_Bool combine(short x,short y,short a[])
{
    if(x!=y)
    {
        a[y]=x;
        return 1;
    }
    else return 0;
}
int main()
{
	int n,i,x,y,m;
    scanf("%d",&n);
    m=n;
    n++;
    short a[n],s[n];
    for(i=1;i<n;i++)
    {
        s[i]=i;
    }
    memset(a,0,sizeof(a));
    for(i=2;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        a[x]++;
        a[y]++;
        if(combine(search(x,s),search(y,s),s))
        {
            m--;
        }
    }
    if(m==1)
    {
        for(i=1;i<n;i++)
        {
            if(a[i]==1)
            {
                printf("%d\n",i);
            }
        }
    }
    else
    {
        printf("Error: %d components",m);
    }
	return 0;
}