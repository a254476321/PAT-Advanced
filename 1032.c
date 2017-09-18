#include<stdio.h>

int main()
{
    int v, w, x, y, n;
    int b[100000];
    _Bool a[100000] = {0};
    scanf("%d%d%d", &v, &w, &n);
    while(n--)
    {
        scanf("%d %*c %d", &x, &y);
        b[x] = y;
    }
    while(v != -1)
    {
        a[v] = 1;
        v = b[v];
    }
    while(w != -1 && a[w] == 0)
    {
        w = b[w];
    }
    if(w == -1)
    {
        puts("-1");
    }
    else
    {
        printf("%05d", w);
    }
	return 0;
}