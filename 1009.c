#include<stdio.h>
#include<string.h> 
int main()
{
	int n,n1,n2,i,j;
    double z;
    scanf("%d",&n1);
    int a1[n1];
    scanf("%d %lf",&i,&z);
    double a[i+1];
    a[i]=z;
    a1[0]=i;
    for(i=1;i<n1;i++)
    {
        scanf("%d %lf",&j,&z);
        a[j]=z;
        a1[i]=j;
    }
    scanf("%d",&n2);
    int b1[n2+n1+1];
    scanf("%d %lf",&i,&z);
    double b[i+1];
    b[i]=z;
    b1[0]=i;
    for(i=1;i<n2;i++)
    {
        scanf("%d %lf",&j,&z);
        b[j]=z;
        b1[i]=j;
    }
    n=a1[0]+b1[0]+1;
    double c[n];
    memset(c,0,sizeof(c));
    for(i=0;i<n1;i++)
    {
        for(j=0;j<n2;j++)
        {
            c[a1[i]+b1[j]]+=a[a1[i]]*b[b1[j]];
        }
    }
    n2=0;
    for(i=0;i<n;i++)
    {
        if(c[i]!=0)
        {
            b1[n2++]=i;
        }
    }
    printf("%d",n2);
    while(n2--)
    {
        printf(" %d %.1lf",b1[n2],c[b1[n2]]);
    }
	return 0;
}