#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void *a, const void *b)
{
    return *(short*)b - *(short*)a;
}
short search(short x, short a[])
{
    return a[x] == -1 ? x : (a[x] = search(a[x], a));
}
void combine(short x, short y, short  a[])
{
    x = search(x, a);
    y = search(y, a);
    if(x == y)
    {
        return;
    }
    else
    {
        x > y ? (a[x] = y) : (a[y] = x);
    }
}
int main()
{
    int n, i, j, k, x, y;
    short a[1001], c[1001];
    scanf("%d", &n);
	short b[n];
    _Bool flag[1001];
    memset(flag+1, 0, 1000);
    memset(c, 0, sizeof(c));
    memset(a, 255, sizeof(a));
    for(i=0; i<n; i++)
    {
        scanf("%d: ", &j);
        scanf("%d", &x);
        while(--j)
        {
            scanf("%d", &y);
            combine(x, y, a);
        }
        b[i] = x;
    }
    for(i=0; i<n; i++)
    {
        j = search(b[i], a);
        c[j]++;
        b[i] = j;
    }
    memset(a, 0, sizeof(a));
    k = 0;
    for(i=0; i<n; i++)
    {
        j = b[i];
        if(flag[j] == 1)
        {
            continue;
        }
        a[k++] = c[j];
        flag[j] = 1;
    }
    printf("%d\n", k);
    qsort(a, k, sizeof(a[0]),cmp);
    printf("%d", a[0]);
    for(i=1; i<k; i++)
    {
        printf(" %d",a[i]);
    }
	return 0;
}