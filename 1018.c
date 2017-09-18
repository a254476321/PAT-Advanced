#include<stdio.h>
int main()
{
	int m,n,sp,r,x,y,z;
    scanf("%d%d%d%d",&m,&n,&sp,&r);
    int c[n+1],d[n+1][n+1];
    for(i=1;i<=n;i++)
    {
        scanf("%d",&c[i]);
    }
    for(i=0;i<r;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        d[x][y]=z;
        d[y][x]=z;
    }
	return 0;
}