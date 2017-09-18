#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct person
{
    char id[16],si[9],so[9];
} PERSON;
int cmp(const void *a,const void *b)
{
    return strcmp(((PERSON*)a)->si,((PERSON*)b)->si);
}
int cmp2(const void *a,const void *b)
{
    return strcmp(((PERSON*)b)->so,((PERSON*)a)->so);
}
int main()
{
	int n,i;
    scanf("%d",&n);
    PERSON p[n];
    for(i=0;i<n;i++)
    {
        scanf("%s%s%s",p[i].id,p[i].si,p[i].so);
    }
    qsort(p,n,sizeof(p[0]),cmp);
    printf("%s ",p[0].id);
    qsort(p,n,sizeof(p[0]),cmp2);
    printf("%s",p[0].id);
	return 0;
}