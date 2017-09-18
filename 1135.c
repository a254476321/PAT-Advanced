#include<stdio.h>
#include<stdlib.h>
_Bool flag;
short RH(short start, short end, const int a[])
{
    if(start == end)
    {
        return a[start] > 0;
    }
    if(a[start] < 0 && a[start + 1] < 0)
    {
        flag = 0;
        return -1;
    }
    short i;
    for(i = start + 1; i <= end && abs(a[i]) < abs(a[start]); i++);
    if(a[start] < 0 && i <= end && a[i] < 0)
    {
        flag = 0;
        return -1;
    }
    i--;
    if(i == end || i == start)
    {
        if(RH(start + 1, end, a) != 0)
        {
            flag = 0;
            return -1;
        }
        return a[start] > 0;
    }
    short n = RH(start + 1, i, a);
    if(n == RH(i + 1, end, a))
    {
        return n + (a[start] > 0);
    }
    else
    {
        flag = 0;
        return -1;
    }
}
int main()
{
    short n, i, m;
    int a[30];
    scanf("%hd", &n);
    while(n--)
    {
        scanf("%hd", &m);
        for(i = 0; i < m; i++)
        {
            scanf("%d", a + i);
        }
        flag = 1;
        RH(0, m - 1, a);
        if(a[0] > 0 && flag)
        {
            puts("Yes");
        }
        else
        {
            puts("No");
        }
    }
	return 0;
}