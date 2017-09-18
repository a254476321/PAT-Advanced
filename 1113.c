#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    return *(int*)b-*(int*)a;
}
int main()
{
	int n,i;
    long sum;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    if((n&1)==1){
        printf("1 ");
    }
    else{
        printf("0 ");
    }
    sum=a[0];
    for(i=(n+1)>>1;i<n;i++)
    {
       sum-=a[i];
    }
    n=(n+1)>>1;
    for(i=1;i<n;i++)
    {
        sum+=a[i];
    }
    printf("%ld",sum);
	return 0;
}