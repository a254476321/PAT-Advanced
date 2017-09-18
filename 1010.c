#include<stdio.h>
int main()
{
    int s[75]={0,1,2,3,4,5,6,7,8,9,[49]=10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35},*p=s-48,i,t,r;
	char a[11],b[11],*aa,*bb,max;
    long x,y,start,end,mid;
    scanf("%s%s%d%d",a,b,&t,&r);
    if(t==1)
    {
        aa=a;
        bb=b;
    }
    else
    {
        aa=b;
        bb=a;
    }
    x=0;
    for(i=0;aa[i]!='\0';i++)
    {
        x=x*r+p[(int)aa[i]];
    }
    max=0;
    for(i=0;bb[i]!='\0';i++)
    {
        if(bb[i]>max){
            max=bb[i];
        }
    }
    start=p[(int)max]+1;
    end=x>start?x+1:start+1;
    while(start<=end)
    {
        mid=(start&end)+((start^end)>>1);
        y=0;
        for(i=0;bb[i]!='\0';i++)
        {
            if(y>x/mid) {y=x+1; break;}
            y=y*mid+p[(int)bb[i]];
        }
        if(y<x)
        {
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    y=0;
    for(i=0;bb[i]!='\0';i++)
    {
        y=y*start+p[(int)bb[i]];
        if(y>x) break;
    }
    if(y==x)
    {
        printf("%ld",start);
    }
    else
    {
        printf("Impossible");
    }
	return 0;
}