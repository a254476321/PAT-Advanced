#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}
int *pre,*arr;
void p(int index,const int ch[][2])
{
    static int i;
    if(index!=-1)
    {
        p(ch[index][0],ch);
        pre[index]=arr[i++];
        p(ch[index][1],ch);
    }
    
}
int main()
{
    int n,i,j;
    scanf("%d",&n);
	int a[n][2],s[n],s2[n];
    for(i=0;i<n;i++)
    {
        scanf("%d%d",a[i],a[i]+1);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",s+i);
    }
    qsort(s,n,sizeof(s[0]),cmp);
    pre=s2;
    arr=s;
    p(0,a);
    s[0]=0;
    i=0;
    j=1;
    while(j<n)
    {
        if(a[s[i]][0]!=-1)
        {
            s[j++]=a[s[i]][0];
        }
        if(a[s[i]][1]!=-1)
        {
            s[j++]=a[s[i]][1];
        }
        i++;
    }
    for(i=0;i<n-1;i++)
    {
        printf("%d ",s2[s[i]]);
    }
    printf("%d",s2[s[i]]);
	return 0;
}