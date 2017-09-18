#include<stdio.h>
_Bool p(const int a[],int n)
{
    int i;
    for(i=n/2;i>-1;i--)
    {
        if(a[i]!=a[n-i-1])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
	int x,b,i=0,a[30];
    scanf("%d%d",&x,&b);
    while(x!=0)
    {
        a[i++]=x%b;
        x/=b;
    }
    if(0==i)
    {
        a[i++]=0;
    }
    if(p(a,i))
    {
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    for(i--;i>0;i--)
    {
        printf("%d ",a[i]);
    }
    printf("%d",a[0]);
	return 0;
}