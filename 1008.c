#include<stdio.h>
int main()
{
	int n,x,i=0,t=0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&x);
        if(x>i)
        {
            t+=(x-i)*6+5;
        }
        else
        {
            t+=(i-x)*4+5;
        }
        i=x;
    }
    printf("%d",t);
	return 0;
}