#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct property{
    short id,es,num;
    double ar;
} PROPERTY;
int cmp(const void *a, const void *b)
{
    PROPERTY *x = (PROPERTY*)a, *y = (PROPERTY*)b;
    return x->ar == y->ar ? x->id - y->id : (y->ar > x->ar ? 1 : -1);
}
short search(short x, short a[])
{
    return a[x] == -1 ? x : (a[x] = search(a[x],a));
}
_Bool combine(short x,short y,short a[])
{
    if(x == y)
    {
        return 0;
    }
    else if(x > y)
    {
        a[x] = y;
    }
    else
    {
        a[y] = x;
    }
    return 1;
}
int main()
{
	int n, m, i, j, k, people, d, x, ar[10000] = {0};
    short a[10000], b[10000] = {0}, es[10000] = {0};
    _Bool flag[10000];
    memset(flag,0,10000);
    memset(a,255,sizeof(a));
    scanf("%d", &n);
    short id[n];
    PROPERTY p[n];
    for(i=0; i<n; i++)
    {
        scanf("%d", &d);
        id[i] = d;
        people = 0;
        scanf("%d%d",&x,&m);
        if(x != -1 && combine(search(x,a), search(d,a), a))
        {
            people++;
        }
        if(m != -1 && combine(search(m,a), search(d,a), a))
        {
            people++;
        }
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d",&x);
            if(combine(search(x,a), search(d,a), a))
            {
                people++;
            }
        }
        scanf("%d%d",&m,&x);
        es[d] = m;
        ar[d] = x;
        b[d] = people;
    }
    for(i=0; i<n; i++)
    {
        j=id[i];
        k = search(j, a);
        if(k == j)
        {
            continue;
        }
        es[k] += es[j];
        ar[k] += ar[j];
        b[k] += b[j];
        id[i] = k;
    }
    k = 0;
    for(i=0; i<n; i++)
    {
        if(!flag[id[i]])
        {
            j = id[i];
            p[k].id = j;
            p[k].num = b[j] + 1;
            p[k].es = es[j];
            p[k].ar = (double)ar[j] / p[k].num;
            k++;
            flag[j] = 1;
        }
    }
    qsort(p,k,sizeof(p[0]),cmp);
    printf("%d\n",k);
    for(i=0; i<k; i++)
    {
        printf("%04d %d %.3lf %.3lf\n",p[i].id,p[i].num,(double)p[i].es / p[i].num,p[i].ar);
    }
	return 0;
}