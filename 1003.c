#include <stdio.h>
#include<string.h>
int main()
{
    int n,m,c1,c2,i,j,k,inf;
	scanf("%d%d%d%d",&n,&m,&c1,&c2);
	int e[n][n],team[n],dis[n],t[n],num[n];
	_Bool book[n];
	memset(book,0,n);
	memset(e,6,sizeof(e));
	inf=e[0][0];
	for(i=0; i<n; i++)
	{
		num[i]=1;
		scanf("%d",&team[i]);
		t[i]=team[i];
	}
    t[c1]=0;
	while(m--)
	{
		scanf("%d%d%d",&i,&j,&k);
		e[i][j]=k;
		e[j][i]=k;
	}
	for(i=0; i<n; i++)
	{
		dis[i]=e[c1][i];
	}
	book[c1]=1;
	for(i=1; i<n; i++)
	{
		m=inf;
		for(j=0; j<n; j++)
		{
			if(!book[j] && dis[j]<m)
			{
				m=dis[j];
				k=j;
			}
		}
		if(m>dis[c2])
		{
			break;
		}
		book[k]=1;
		for(j=0; j<n; j++)
		{
			if(!book[j]  && e[k][j]<inf)
			{
				m=dis[k]+e[k][j];
				if(dis[j]>m)
				{
					dis[j]=m;
					t[j]=team[j]+t[k];
					num[j]=num[k];
				}
				else if(dis[j]==m)
				{
					num[j]+=num[k];
					if(t[j]<t[k]+team[j])
					{
						t[j]=t[k]+team[j];
					}
				}
			}
			
		}
	}
	printf("%d %d",num[c2],t[c2]+team[c1]);
    return 0;
}