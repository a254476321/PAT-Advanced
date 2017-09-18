#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct tree{
    short weight;
    struct tree *next;
} TREE;
int cmp(const void *a,const void *b)
{
    TREE *x = *(TREE**)a,*y = *(TREE**)b;
    while(x != NULL && y != NULL && x->weight == y->weight)
    {
        x = x->next;
        y = y->next;
    }
    if(x == NULL)
    {
        return 1;
    }
    else if(y == NULL)
    {
        return -1;
    }
    else
    {
        return y->weight - x->weight;
    }
}
int main()
{
	int n,m,s,i,j,k,x,sum;
    scanf("%d%d%d",&n,&m,&s);
    int a[n];
    short b[n];
    TREE *c[n-m],*p,*head;
    _Bool leaf[n];
    memset(leaf,0,n);
    for(i=0; i<n; i++)
    {
        scanf("%d",a+i);
    }
    for(i=0; i<m; i++)
    {
        scanf("%d%d",&k,&j);
        leaf[k]=1;
        while(j--)
        {
            scanf("%d",&x);
            b[x]=k;
        }
    }
    k = 0;
    for(i=1; i<n; i++)
    {
        if(leaf[i] == 0)
        {
            sum= a[0] + a[i];
            j = b[i];
            while(j != 0 && sum <= s)
            {
                sum += a[j];
                j = b[j];
            }
            if(sum == s)
            {
                head = (TREE*)malloc(sizeof(TREE));
                head->weight = a[i];
                head->next = NULL;
                j = b[i];
                while(j != 0)
                {
                    p = head;
                    head = (TREE*)malloc(sizeof(TREE));
                    head->weight = a[j];
                    head->next = p;
                    j = b[j];
                }
                c[k++] = head;
            }
        }
    }
    qsort(c,k,sizeof(c[0]),cmp);
    for(i=0; i<k; i++)
    {
        printf("%d",a[0]);
        head = c[i];
        while(head != NULL)
        {
            printf(" %d",head->weight);
            p = head;
            head = head->next;
            free(p);
        }
        putchar('\n');
    }
    if(a[0] == s)
    {
        printf("%d",s);
    }
	return 0;
}