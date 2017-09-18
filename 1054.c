#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,m,x,y;
    scanf("%d%d%d",&n,&m,&x);
    n *= m;
    m = 0;
    while(--n)
    {
        scanf("%d",&y);
        if(x == y)
        {
            m++;
        }
        else if(m == 0)
        {
            x = y;
        }
        else
        {
            m--;
        }
    }
    printf("%d",x);
	return 0;
}