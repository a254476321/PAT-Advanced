#include<stdio.h>
#include<string.h>
int p1(int x, const int a[], int b[])
{
    if(x == 0)
    {
        return 1;
    }
    else if(b[x] != 0)
    {
        return b[x] + 1;
    }
    return (b[x] = p1(a[x],a,b)) + 1;
}
int main()
{
	int n,i,j,x,min;
    double p,r;
    scanf("%d%lf%lf", &n, &p, &r);
    r = 1 + r / 100;
    int a[n],b[n];
    b[0] = 0;
    _Bool root[n];
    memset(root,0,n);
    memset(b,0,sizeof(b));
    min = n;
    for(i=0; i<n; i++)
    {
        scanf("%d",&j);
        if(j == 0)
        {
            root[i] = 1;
        }
        else
        {
            while(j--)
            {
                scanf("%d",&x);
                a[x] = i;
            }
        }
    }
    for(i=0; i<n; i++)
    {
        x = p1(i,a,b) - 1;
        if(root[i] == 1 && min > x)
        {
            min = x;
        }
    }
    j = 0;
    for(i=0; i<n; i++)
    {
        if(root[i] == 1 && min == b[i])
        {
            j++;
        }
    }
    while(min--)
    {
        p *= r;
    }
    printf("%.4lf %d",p,j);
	return 0;
}