#include<stdio.h>
#include<stdlib.h>
int main()
{
    short value[100000];
    int next[100000], x, y, z, first, n, i;
    _Bool a[10001] = {0};
    scanf("%d%d", &first, &n);
    int b[n];
    for(i=0; i<n; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        next[x] = z;
        value[x] = y;
    }
    a[abs(value[first])] = 1;
    x = 0;
    printf("%05d %d ", first, value[first]);
    first = next[first];
    while(first != -1)
    {
        y = abs(value[first]);
        if(a[y] == 0)
        {
            a[y] = 1;
            printf("%05d\n%05d %d ", first, first, value[first]);
        }
        else
        {
            b[x++] = first;
        }
        first = next[first];
    }
    puts("-1");
    if(x != 0)
    {
        x--;
        for(i=0; i<x; i++)
        {
            printf("%05d %d %05d\n", b[i], value[b[i]], b[i + 1]);
        }
        printf("%05d %d -1\n", b[x], value[b[x]]);
    }
    return 0;
}