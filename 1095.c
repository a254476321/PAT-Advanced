#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct car
{
    char num[8], time[9];
    _Bool m;
} CAR;
int cmp(const void *a, const void *b)
{
    CAR *x = (CAR*)a, *y = (CAR*)b;
    short i = strcmp(x->num, y->num);
    return i == 0 ? strcmp(x->time, y->time) : i;
}
int cmp1(const void *a, const void *b)
{
    return strcmp(((CAR*)a)->time, ((CAR*)b)->time);
}
int difftime(char a[], char b[])
{
    short h, m, s, h2, m2, s2;
    sscanf(a, "%hd:%hd:%hd", &h, &m, &s);
    sscanf(b, "%hd:%hd:%hd", &h2, &m2, &s2);
    return (h - h2) * 3600 + (m - m2) * 60 + s - s2;
}
int main()
{
    int n, m, i, max = 0;
    int x = 0, y = 0, z;
    scanf("%d%d", &n, &m);
    CAR a[n], b[n];
    char c[n >> 1][8], temp[9];
    int time[n >> 1];
    memset(time, 0, n << 1);
    for(i = 0; i < n; i++)
    {
        scanf("%s%s ", a[i].num, a[i].time);
        if(getchar() == 'i')
        {
            a[i].m = 1;
        }
        else
        {
            a[i].m = 0;
        }
        scanf("%*s");
    }
    qsort(a, n, sizeof(CAR), cmp);
    strcpy(c[0], a[1].num);
    
    for(i = 1; i < n; i++)
    {
        if(strcmp(a[i].num, a[i - 1].num) == 0 && a[i].m + 1 == a[i - 1].m)
        {
            strcpy(c[0], a[i].num);
            time[0] += difftime(a[i].time, a[i - 1].time);
            b[y++] = a[i - 1];
            b[y++] = a[i++];
            break;
        }
    }
    for(; i < n; i++)
    {
        if(strcmp(a[i].num, a[i - 1].num) == 0 && a[i].m + 1 == a[i - 1].m)
        {
            if(strcmp(a[i].num, c[x]) != 0)
            {
                strcpy(c[++x], a[i].num);
            }
            time[x] += difftime(a[i].time, a[i - 1].time);
            b[y++] = a[i - 1];
            b[y++] = a[i];
        }
    }
    for(i = 0; i <= x; i++)
    {
        if(max < time[i])
        {
            max = time[i];
        }
    }
    z = x;
    qsort(b, y, sizeof(CAR), cmp1);
    scanf("%s", temp);
    for(x = i = 0; strcmp(temp, b[i].time) >= 0; i++)
    {
        b[i].m == 1 ? x++ : x--;
    }
    printf("%d\n", x);
    while(--m)
    {
        scanf("%s", temp);
        for(; strcmp(temp, b[i].time) >= 0; i++)
        {
            b[i].m == 1 ? x++ : x--;
        }
        printf("%d\n", x);
    }
    for(i = 0; i<=z; i++)
    {
        if(time[i] == max)
        {
            printf("%s ", c[i]);
        }
    }
    printf("%02d:%02d:%02d", max / 3600, max % 3600 / 60, max % 60);
	return 0;
}