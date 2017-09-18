#include<stdio.h>
#include<stdlib.h>
typedef struct link{
    int addr, value;
} LINK;
int cmp(const void *a, const void *b)
{
    return ((LINK*)a)->value - ((LINK*)b)->value;
}
int main()
{
    int n, a[100000], head, i, x;
    _Bool b[100000] = {0};
    scanf("%d%d", &n, &head);
    LINK p[n], p2[n];
    if(head == -1)
    {
        puts("0 -1");
        return 0;
    }
    for(i=0; i<n; i++)
    {
        scanf("%d%d%d", &p[i].addr, &p[i].value, &x);
        a[p[i].addr] = x;
    }
    while(head != -1)
    {
        b[head] = 1;
        head = a[head];
    }
    for(i=x=0; i<n; i++)
    {
        if(b[p[i].addr] == 1)
        {
            p2[x++] = p[i];
        }
    }
    qsort(p2, x, sizeof(LINK), cmp);
    printf("%d %05d\n", x, p2[0].addr);
    x--;
    for(i=0; i<x; i++)
    {
        printf("%05d %d %05d\n", p2[i].addr, p2[i].value, p2[i + 1].addr);
    }
    printf("%05d %d -1", p2[i].addr, p2[i].value);
	return 0;
}