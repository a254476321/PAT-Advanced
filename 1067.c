#include<stdio.h>
#include<string.h>
int search(int x, int a[])
{
    return a[x] == -1 ? x : (a[x] = search(a[x], a));
}
_Bool combine(int x, int y, int a[])
{
    x = search(x, a);
    y = search(y, a);
    if(x == y)
    {
        return 0;
    }
    else
    {
        a[y] = x;
        return 1;
    }
}
int main()
{
	int n, i, j = 0, k = 0;
    scanf("%d", &n);
    int a[n], b[n];
    memset(b, 255, n << 2);
    for(i=0; i<n; i++)
    {
        scanf("%d", a + i);
    }
    for(i=0; i<n; i++)
    {
        if(a[i] == i)
        {
            j++;
        }
        else if(combine(a[i], i, b))
        {
            k++;
        }
    }
    if(a[0] == 0)
    {
        printf("%d", ((n - j) << 1) - k);
    }
    else
    {
        printf("%d", ((n - j - 1) << 1) - k);
    }
	return 0;
}