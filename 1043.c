#include<stdio.h>
void swap(int *a, int *b)
{
    *a ^= *b ^= *a;
    *b ^= *a;
}
_Bool p1(int a[], int n)
{
    if(n == 0 || n == 1) return 1;
    int i, j;
    for(i=1; i<n; i++)
    {
        swap(a + i, a + i - 1);
    }
    i = 0;
    while(i < n - 1 && a[i] < a[n - 1])
    {
        i++;
    }
    j = i;
    while(j < n && a[j] >= a[n - 1])
    {
        j++;
    }
    if(j != n)
    {
        return 0;
    }
    if(p1(a, i) && p1(a + i, n - i - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
_Bool p2(int a[],int n)
{
    if(n == 0 || n == 1) return 1;
    int i,j;
    for(i=1; i<n; i++)
    {
        swap(a + i, a + i - 1);
    }
    i = 0; 
    while(i < n - 1 && a[i] >= a[n - 1])
    {
        i++;
    }
    j = i;
    while(j < n && a[j] < a[n - 1])
    {
        j++;
    }
    if(j < n - 1)
    {
        return 0;
    }
    if(p2(a, i) && p2(a + i, n - i - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
	int n, i;
    scanf("%d",&n);
    int a[n];
    for(i=0; i<n; i++)
    {
        scanf("%d", a+i);
    }
    if(a[0] > a[1])
    {
        if(!p1(a, n))
        {
            puts("NO");
            return 0;
        }
    }
    else if(!p2(a, n))
    {
        puts("NO");
        return 0;
    }
    puts("YES");
    printf("%d", a[0]);
    for(i=1; i<n; i++)
    {
        printf(" %d", a[i]);
    }
	return 0;
}