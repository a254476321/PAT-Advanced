#include <stdio.h>
int main()
{
    int n,i,j,max=-1,f1,f2,sum;
    scanf("%d",&n);
    int s[n];
    for(i=0; i<n; i++)
    {
        scanf("%d",&s[i]);
    }
    for(i=0; i<n; i++)
    {
        if(s[i]<0) continue;
        else
        {
            sum=s[i];
            for(j=i+1; j<n; j++)
            {
                if(s[j]<1)
                {
                    if(sum>max)
                    {
                        max=sum;
                        f1=i;
                        f2=j-1;
                    }
                    sum+=s[j];
                    if(sum<0)
                    {
                        break;
                    }
                }
                else sum+=s[j];
            }
            if(j==n&&sum>max)
            {
                max=sum;
                f1=i;
                f2=j-1;
                break;
            }
            while(++i<n&&s[i]>0);
        }
    }
    if(max>-1)
    {
        printf("%d %d %d",max,s[f1],s[f2]);
    }
    else
    {
        printf("0 %d %d",s[0],s[n-1]);
    }
    return 0;
}