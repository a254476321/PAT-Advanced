#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}
void q(int a[], const int b[], int n, int index)
{
    static int i;
    if(index <= n)
    {
        q(a, b, n, index << 1);
        a[index - 1] = b[i++];
        q(a, b, n, (index << 1) + 1);
    }
}
int main()
{
	int n, i;
    scanf("%d", &n);
    int a[n], b[n];
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(a[0]), cmp);
    q(b, a, n, 1);
    for(i=0; i<n-1; i++)
    {
        printf("%d ", b[i]);
    }
    printf("%d", b[i]);
	return 0;
}