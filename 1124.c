#include<stdio.h>
#include<string.h>
int main()
{
    int n,m,l,i=0,j,k,low,high,mid;
    scanf("%d%d%d",&n,&l,&m);
	m--;
    k=n/l+1;
    char name[k][21],*pn[k],*p;
    for(j=0; j<k; j++)
    {
        pn[j]=name[j];
    }
    for(k=0;i<n;i++)
    {
        for(;i<m&&i<n;i++)
        {
            scanf("%*s");
        }
		if(i==n)
		{
			break;
		}
        scanf("%s",name[k]);
        low=0;
        high=k-1;
        while(low<=high)
        {
            mid=(low+high)>>1;
            j=strcmp(pn[mid],pn[k]);
            if(j>0)
            {
                high=mid-1;
            }
            else if(j<0)
            {
                low=mid+1;
            }
            else
            {
                break;
            }
        }
        if(j==0)
        {
            m++;
        }
        else
        {
            puts(pn[k]);
            while(low<k)
            {
                p=pn[k];
                pn[k]=pn[low];
                pn[low++]=p;
            }
            k++;
			m+=l;
        }
    }
	if(k==0)
	{
		puts("Keep going...");
	}
    return 0;
}