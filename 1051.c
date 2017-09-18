#include<stdio.h>
int main()
{
	int n,m,k,cur,i,j,x;
    scanf("%d%d%d",&n,&m,&k);
    int stack[n];
    while(k--)
    {
        cur=0;
        stack[0]=1;
        j=2;
        for(i=0;i<m;i++)
        {
            scanf("%d",&x);
            while(stack[cur]!=x&&cur!=n-1&&j<m+1)
            {
                stack[++cur]=j++;
            }
            if(stack[cur]==x)
            {
                cur--;
                if(cur==-1)
                {
                    stack[++cur]=j++;
                }
            }
            else
            {
                scanf("%*[^\n]");
                printf("NO\n");
                break;
            }
        }
        if(i==m)
        {
            printf("YES\n");
        }
    }
	return 0;
}