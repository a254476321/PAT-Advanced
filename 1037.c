#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}
int main()
{
	int n, m, i, j, min;
    long sum = 0;
    scanf("%d", &n);
    int a[n];
    for(i=0; i<n; i++)
    {
        scanf("%d", a+i);
    }
    qsort(a, n, sizeof(a[0]),cmp);
    scanf("%d", &m);
    int b[m];
    for(i=0; i<m; i++)
    {
        scanf("%d", b+i);
    }
    qsort(b, m, sizeof(b[0]),cmp);
    min = n<m ? n : m; 
    for(i=0; i<min && (a[i]|b[i])>0; i++)
    {
        sum += a[i] * b[i];
    }
    for(j=1; min-j>=i&&(a[n-j]&b[m-j])<0; j++)
    {
        sum += a[n-j] * b[m-j];
    }
    printf("%ld", sum);
	return 0;
}