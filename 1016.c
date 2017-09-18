#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct phone{
    char name[21],time[9];
    _Bool status;
    int mouth;
} PHONE;
int cmp(const void *a,const void *b)
{
    int i;
    PHONE *x=(PHONE*)a,*y=(PHONE*)b;
    i=strcmp(x->name,y->name);
    return i==0?strcmp(x->time,y->time):i;
}
double ctime(const char a[],const char b[],const int c[])
{
    double cent;
    int d1,d2,h1,h2,m1,m2,i,minute;
    sscanf(a,"%d:%d:%d",&d1,&h1,&m1);
    sscanf(b,"%d:%d:%d",&d2,&h2,&m2);
    minute=(d2-d1)*1440+(h2-h1)*60+m2-m1;
    cent=(d2-d1)*60*c[24]+m2*c[h2]-m1*c[h1];
    i=0;
    if(h2>h1)
    {
        for(;h1<h2;h1++)
        {
            i+=c[h1];
        }
        cent+=i*60;
    }
    else
    {
        for(;h2<h1;h2++)
        {
            i+=c[h2];
        }
        cent-=i*60;
    }
    cent/=100;
    printf("%s %s %d $%.2lf\n",a,b,minute,cent);
    return cent;
}
int main()
{
	int i,n,toll[25];
    double sum;
    char s[21];
    toll[24]=0;
    for(i=0;i<24;i++)
    {
        scanf("%d",&toll[i]);
        toll[24]+=toll[i];
    }
    scanf("%d",&n);
    PHONE p[n];
    for(i=0;i<n;i++)
    {
        scanf("%s%d:%s%s",p[i].name,&p[i].mouth,p[i].time,s);
        if(s[1]=='f')
        {
            p[i].status=0;
        }
        else {
            p[i].status=1;
        }
    }
    qsort(p,n,sizeof(p[0]),cmp);
    for(i=1;i<n;i++)
    {
        if(p[i].status==p[i-1].status-1&&strcmp(p[i].name,p[i-1].name)==0)
        {
            strcpy(s,p[i].name);
            printf("%s %02d\n",s,p[i].mouth);
            sum=ctime(p[i-1].time,p[i].time,toll);
            break;
        }
    }
    for(i++; i<n; i++)
    {
        if(p[i].status==p[i-1].status-1&&strcmp(p[i].name,p[i-1].name)==0)
        {
            if(strcmp(s,p[i].name)!=0)
            {
                printf("Total amount: $%.2lf\n",sum);
                strcpy(s,p[i].name);
                printf("%s %02d\n",s,p[i].mouth);
                sum=ctime(p[i-1].time,p[i].time,toll);
            }
            else {
                sum+=ctime(p[i-1].time,p[i].time,toll);
            }
        }
    }
    printf("Total amount: $%.2lf\n",sum);
	return 0;
}