#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct customer{
    char a[9];
    int t;
} CUSTOMER;
int cmp(const void *a,const void *b)
{
    return strcmp(((CUSTOMER*)a)->a,((CUSTOMER*)b)->a);
}
int ctime(const char a[],const char b[])
{
    if(strcmp(a,b)<=0) return 0;
    int h1,m1,s1,h2,m2,s2;
    sscanf(a,"%d:%d:%d",&h1,&m1,&s1);
    sscanf(b,"%d:%d:%d",&h2,&m2,&s2);
    return (h1-h2)*3600+(m1-m2)*60+s1-s2;
}
void htime(char a[],int b)
{
    int h,m,s;
    sscanf(a,"%d:%d:%d",&h,&m,&s);
    m+=b;
    h+=m/60;
    m%=60;
    sprintf(a,"%02d:%02d:%02d",h,m,s);
}
int main()
{
	int n,m,i,j,s=0,min;
    scanf("%d%d",&n,&m);
    char w[m][9],t[9];
    CUSTOMER c[n];
    for(i=0;i<m;i++)
    {
        strcpy(w[i],"08:00:00");
    }
    for(i=0;i<n;i++)
    {
        scanf("%s%d",c[i].a,&c[i].t);
        if(strcmp(c[i].a,"17:00:00")>0)
        {
            n--;
            i--;
            continue;
        }
    }
    qsort(c,n,sizeof(c[0]),cmp);
    for(i=0;i<n;i++)
    {
        min=0;
        strcpy(t,w[0]);
        for(j=1;j<m;j++)
        {
            if(strcmp(w[j],t)<0)
            {
                min=j;
                strcpy(t,w[j]);
            }
        }
        s+=ctime(w[min],c[i].a);
        if(strcmp(w[min],c[i].a)<0)
        {
            strcpy(w[min],c[i].a);
        }
        htime(w[min],c[i].t);
    }
    printf("%.1lf",(double)s/n/60);
	return 0;
}