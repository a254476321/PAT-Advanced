#include<stdio.h>
#include<string.h>
short n, min = 999999;
_Bool dfs(short start, short end, const short a[][10000], int num)
{
    if(start == end)
    {
        if(min > num)
        {
            min = num;
            
        }
        return 1;
    }
    short i;
    for(i=0; i<n; i++)
    {
        if(a[i][start] != -1)
        {
            dfs(a[i][start], end, a, num + 1);
        }
    }
}
int main()
{
    short m, k, i, x, y;
    scanf("%hd", &n);
	short a[n][10000];
    s = a;
    memset(a, 255, sizeof(a));
    for(i=0; i<n; i++)
    {
        scanf("%hd", &m);
        scanf("%hd", &y);
        while(--m)
        {
            scanf("%hd", &x);
            a[y] = x;
            y = x;
        }
    }
    scanf("%hd", &m);
    while(m--)
    {
        scanf("%hd%hd", &x, &y);
        dfs(x, y, a, 0);
    }
	return 0;
}