#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    return *(int*)a - *(int*)b;
}
void swap(int *a,int *b)
{
    *a^=*b;
    *b^=*a;
    *a^=*b;
}
int main()
{
	int n,i,j,k;
    scanf("%d", &n);
    int a[n],b[n];
    for(i=0; i<n; i++)
    {
        scanf("%d",a+i);
    }
    for(i=0; i<n; i++)
    {
        scanf("%d",b+i);
    }
    for(i=1; i<n && b[i]>=b[i-1]; i++);
    for(j=i;j<n && a[j]==b[j]; j++);
    if(j == n)
    {
        puts("Insertion Sort");
        qsort(b,i+1,sizeof(b[0]),cmp);
    }
    else
    {
        puts("Heap Sort");
        for(i=n-1; i>-1; i--)
        {
            if(b[i] < b[0])
            {
                break;
            }
        }
        swap(b + i,b);
        j = 0;
        while(1)
        {
            k = j << 1;
            if(k + 1 >= i)
            {
                break;
            }
            k + 2 < i && b[k + 2] > b[k + 1] ? k += 2 : k++;
            swap(b + j,b + k);
            j = k;
        }
    }
    printf("%d",b[0]);
    for(i=1; i<n; i++)
    {
        printf(" %d",b[i]);
    }
	return 0;
}