#include<stdio.h>
#include<stdlib.h>
typedef struct student{
    int id;
    short c,m,e,a,cn,mn,en,an;
} STU;
int cmp(const void *a,const void *b)
{
    return ((STU*)a)->id-((STU*)b)->id;
}
int cmp1(const void *a,const void *b)
{
    return (*(STU**)b)->a-(*(STU**)a)->a;
}
int cmp2(const void *a,const void *b)
{
    return (*(STU**)b)->c-(*(STU**)a)->c;
}
int cmp3(const void *a,const void *b)
{
    return (*(STU**)b)->m-(*(STU**)a)->m;
}
int cmp4(const void *a,const void *b)
{
    return (*(STU**)b)->e-(*(STU**)a)->e;
}
int main()
{
    char a[]={'A','C','M','E'};
	int n,m,i,x,y,z;
    scanf("%d%d",&n,&m);
    STU s[n],*p1[n],*p2[n],*p3[n],*p4[n],*s2;
    for(i=0;i<n;i++)
    {
        p1[i]=p2[i]=p3[i]=p4[i]=&s[i];
        scanf("%d%d%d%d",&s[i].id,&x,&y,&z);
        s[i].c=x;
        s[i].m=y;
        s[i].e=z;
        s[i].a=(x+y+z+1)/3;
    }
    qsort(s,n,sizeof(s[0]),cmp);
    qsort(p1,n,sizeof(p1[0]),cmp1);
    qsort(p2,n,sizeof(p2[0]),cmp2);
    qsort(p3,n,sizeof(p3[0]),cmp3);
    qsort(p4,n,sizeof(p4[0]),cmp4);
    if(n>0)
    {
        p1[0]->an=0;
        p2[0]->cn=0;
        p3[0]->mn=0;
        p4[0]->en=0;
    }
    for(i=1;i<n;i++)
    {
        if(p1[i]->a==p1[i-1]->a)
            p1[i]->an=p1[i-1]->an;
        else p1[i]->an=i;
        if(p2[i]->c==p2[i-1]->c)
            p2[i]->cn=p2[i-1]->cn;
        else p2[i]->cn=i;
        if(p3[i]->m==p3[i-1]->m)
            p3[i]->mn=p3[i-1]->mn;
        else p3[i]->mn=i;
        if(p4[i]->e==p4[i-1]->e)
            p4[i]->en=p4[i-1]->en;
        else p4[i]->en=i;
    }
    while(m--)
    {
        scanf("%d",&i);
        if((s2=bsearch(&i,s,n,sizeof(s[0]),cmp))!=NULL)
        {
            x=0;
            y=s2->an;
            if(s2->cn<y)
            {
                x=1;
                y=s2->cn;
            }
            if(s2->mn<y)
            {
                x=2;
                y=s2->mn;
            }
            if(s2->en<y)
            {
                x=3;
                y=s2->en;
            }
            printf("%d %c\n",y+1,a[x]);
        }
        else{
            printf("N/A\n");
        }
    }
	return 0;
}