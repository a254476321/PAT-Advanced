#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct user{
    int *score;
    short an, id;
    _Bool *a;
} USER;
int cmp(const void *a, const void *b)
{
    USER *p = (USER*)a, *q = (USER*)b;
    return p->score[0] != q->score[0] ? q->score[0] - p->score[0] : (p->an != q->an ? q->an - p->an : p->id - q->id);
}
int main()
{
    int n, k, m, i, x, y;
    scanf("%d%d%d", &n, &k, &m);
    USER u[n + 1];
    int score[k + 1];
    for(i=1; i<=k; i++)
    {
        scanf("%d", score + i);
    }
    for(i=1; i<=n; i++)
    {
        u[i].score = (int*)calloc(k + 1, 4);
        u[i].a = (_Bool*)calloc(k + 1, 1);
        u[i].an = 0;
        u[i].id = i;
    }
    while(m--)
    {
        scanf("%d%d%d", &i, &x, &y);
        u[i].a[x] = 1;
        if(u[i].score[x] < y)
        {
            u[i].score[0] += y - u[i].score[x];
            u[i].score[x] = y;
            if(y == score[x])
            {
                u[i].an++;
            }
        }
        else if(y == 0)
        {
            u[i].a[0] = 1;
        }
    }
    qsort(u + 1, n, sizeof(USER), cmp);
    for(i=x=1; i<n&&u[i].score[0]!=0; i++)
    {
        printf("%d %05d %d", x, u[i].id, u[i].score[0]);
        for(y=1; y<=k; y++)
        {
            if(u[i].a[y])
            {
                printf(" %d", u[i].score[y]);
            }
            else
            {
                printf(" -");
            }
        }
        putchar('\n');
        if(u[i].score[0] != u[i + 1].score[0])
        {
            x = i + 1;
        }
    }
    if(u[i].score[0] != 0)
    {
        printf("%d %05d %d", x, u[i].id, u[i].score[0]);
        for(y=1; y<=k; y++)
        {
            if(u[i].a[y])
            {
                printf(" %d", u[i].score[y]);
            }
            else
            {
                printf(" -");
            }
        }
        i++;
        x++;
    }
    for(; i<=n; i++)
    {
        if(u[i].a[0])
        {
            printf("%d %05d 0", x, u[i].id);
            for(y=1; y<=k; y++)
            {
                if(u[i].a[y])
                {
                    printf(" 0");
                }
                else
                {
                    printf(" -");
                }
            }
        }
    }
    for(i=1; i<=n; i++)
    {
        free(u[i].score);
        free(u[i].a);
    }
	return 0;
}
