#include<stdio.h>
int *in,*post;
short p(short root,short start,short end,short s[][2])
{
    if(start>end) return -1;
    short i=start;
    while(post[root]!=in[i]) i++;
    s[i][0]=p(root-1-end+i,start,i-1,s);
    s[i][1]=p(root-1,i+1,end,s);
    return i;
}
void reverse(short *a,short *b)
{
    while(a<b)
    {
        *a^=*b;
        *b^=*a;
        *a^=*b;
        a++;
        b--;
    }
}
int main()
{
    int n,i,k,j,start,end;
    scanf("%d",&n);
    int a[n],b[n];
    short s[n][2],queue[n];
    in=a;
    post=b;
    for(i=0; i<n; i++)
    {
        scanf("%d",a+i);
    }
    for(i=0; i<n; i++)
    {
        scanf("%d",b+i);
    }
    queue[0]=p(n-1,0,n-1,s);
    start=0;
    end=1;
    b[queue[0]]=1;
    while(start<end)
    {
        i=queue[start];
        if(s[i][0]!=-1)
        {
            b[s[i][0]]=b[i]+1;
            queue[end++]=s[i][0];
        }

        if(s[i][1]!=-1)
        {
            b[s[i][1]]=b[i]+1;
            queue[end++]=s[i][1];
        }
        start++;
    }
    for(i=0; i<n; i++)
    {
        if(b[queue[i]]!=1) break;
    }
    while(i<n)
    {
        j=i;
        k=b[queue[i]];
        if((k&1)==0)
        {
            i++;
            continue;
        }
        while(j+1<n&&k==b[queue[j+1]]) j++;
        reverse(queue+i,queue+j);
        i=j+1;
    }
    printf("%d",a[queue[0]]);
    for(i=1; i<n; i++)
    {
        printf(" %d",a[queue[i]]);
    }
    return 0;
}