#include<stdio.h>
int find(int i,int r[])
{
    if(r[i]==i)
    {
        return i;
    }
    else{
        r[i]=find(r[i],r);
        return r[i];
    }
}
int combine(int x,int y,int *r)
{
    if(x!=y)
    {
        r[y]=x;
        return 1;
    }
    else return 0;
}
int main()
{
	int n,m,k,i,x,num;
    scanf("%d%d%d",&n,&m,&k);
    int a[m][2],r[n+1];
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&a[i][0],&a[i][1]);
    }
    while(k--)
    {
        for(i=1;i<n+1;i++)
        {
            r[i]=i;
        }
        scanf("%d",&x);
        num=n-2;
        for(i=0;i<m;i++)
        {
            if(a[i][0]!=x&&a[i][1]!=x)
            {
                if(combine(find(a[i][0],r),find(a[i][1],r),r))
                {
                    num--;
                }
            }
        }
        printf("%d\n",num);
    }
	return 0;
}