#include<stdio.h>
int main()
{
    int n,m,p,g,i,j,max,x,y;
    scanf("%d%d",&p,&g);
    int a[p],b[p],c[p];
    for(i=0; i<p; i++)
    {
        scanf("%d",a+i);
    }
    for(i=0; i<p; i++)
    {
        scanf("%d",b+i);
    }
    n=p%g==0?p/g:p/g+1;
    y=p;
    while(y>1)
    {
        for(i=0; i<n; i++)
        {
            x=i*g;
            max=a[b[x]];
            m=x+g;
            for(j=x+1; j<m&&j<y; j++)
            {
                if(a[b[j]]>max)
                {
                    c[b[x]]=n+1;
                    x=j;
                    max=a[b[x]];
                }
                else
                {
                    c[b[j]]=n+1;
                }
            }
            b[i]=b[x];
        }
        y=n;
        n=n%g==0?n/g:n/g+1;
    }
    c[b[0]]=1;
    printf("%d",c[0]);
    for(i=1;i<p;i++)
    {
        printf(" %d",c[i]);
    }
    return 0;
}