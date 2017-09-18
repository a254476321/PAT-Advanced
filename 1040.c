#include<stdio.h>
#include<string.h>
int main()
{
    int i,n,max=1,k;
    char a[1001];
    _Bool flag = 1;
    gets(a);
    n = strlen(a);
    for(i=1; i+max-1<n; i++)
    {
        if(i+max<n && a[i-max] == a[i+max])
        {
            k = max;
            while(--k && a[i-k] == a[i+k]);
            if(k == 0)
            {
                flag = 1;
                max++;
                while(i-max>=0 && i+max<n && a[i-max]==a[i+max])
                {
                    max++;
                }
            }
        }
        if(a[i+max-1] == a[i-max])
        {
            k = max;
            while(--k && a[i+k-1] == a[i-k]);
            if(k == 0)
            {
                flag = 0;
                while(i-max>=0 && i+max-1<n && a[i+max-1] == a[i-max])
                {
                    max++;
                }
            }
        }
    }
    if(flag == 1)
    {
        printf("%d",((max-1)<<1)+1);
    }
    else
    {
        printf("%d",(max-1)<<1);
    }
    return 0;
}