#include<stdio.h>
#include<string.h>
int p1(int x, const int a[], int b[])
{
    if(x == -1)
    {
        return 0;
    }
    else if(b[x] != 0)
    {
        return b[x] + 1;
    }
    return (b[x] = p1(a[x],a,b)) + 1;
}
int main()
{
	int n,i,j,k,max = 0;
    double p,r;
    scanf("%d%lf%lf", &n,&p,&r);
    int a[n],b[n];
    memset(b,0,sizeof(b));
    for(i=0; i<n; i++)
    {
        scanf("%d",a+i);
    }
    for(i=0; i<n; i++)
    {
        if(b[i] != 0)
        {
            continue;
        }
        k = p1(i,a,b) - 1;
        if(max < k)
        {
            max = k;
        }
    }
    j = 0;
    for(i=0; i<n; i++)
    {
        if(b[i] == max)
        {
            j++;
        }
    }
    r = 1 + r / 100;
    while(max--)
    {
        p *= r;
    }
    printf("%.2lf %d",p,j);
	return 0;
}