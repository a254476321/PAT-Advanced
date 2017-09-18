#include<stdio.h>
#include<math.h>
_Bool isPrime(int a)
{
    int max,i;
    if((a!=2&&(a&1)==0)||a==1) return 0;
    max=sqrt(a);
    for(i=3;i<=max;i+=2)
    {
        if(a%i==0) return 0;
    }
    return 1;
}
int main()
{
	int n,d,n2;
    while(1)
    {
        scanf("%d",&n);
        if(n<0)
        {
            break;
        }
        scanf("%d",&d);
        if(!isPrime(n))
        {
            printf("No\n");
            continue;
        }
        n2=0;
        while(n!=0)
        {
            n2=n2*d+n%d;
            n/=d;
        }
        if(isPrime(n2))
            printf("Yes\n");
        else printf("No\n");
    }
	return 0;
}