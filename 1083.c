#include<stdio.h>
#include<stdlib.h>
typedef struct stu{
    char name[11],id[11];
    int grade;
} STU;
int cmp(const void *a,const void *b)
{
    return ((STU*)b)->grade-((STU*)a)->grade;
}
int main()
{
    int n,i,start,end,mid,x,y;
    scanf("%d",&n);
    STU s[n];
    for(i=0;i<n;i++)
    {
        scanf("%s%s%d",s[i].name,s[i].id,&s[i].grade);
    }
    qsort(s,n,sizeof(s[0]),cmp);
    scanf("%d%d",&x,&y);
    start=0;
    end=n-1;
    while(start<=end)
    {
        mid=(start+end)>>1;
        if(s[mid].grade<x)
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    x=end;
    start=0;
    while(start<=end)
    {
        mid=(start+end)>>1;
        if(s[mid].grade>y)
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    y=start;
    if(y<=x)
    {
        for(i=y;i<x;i++)
        {
            printf("%s %s\n",s[i].name,s[i].id);
        }
        printf("%s %s\n",s[i].name,s[i].id);
    }
    else{
        puts("NONE");
    }   
	return 0;
}