#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
    *a ^= *b ^= *a;
    *b ^= *a;
}
int common(const int a[],int n,const int b[],int m)
{
    int i = 0,j = 0,k = 0;;
    while(i < n && j < m)
    {
        if(a[i] == b[j])
        {
            i++;
            j++;
            k++;
        }
        else if(a[i] > b[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    return k;
}
int main()
{
	int n, i, j, k, m, **p, start, end, mid, x;
    scanf("%d", &n);
    int a[n];
    p = (int**)malloc(n*sizeof(int*));
    for(i=0; i<n; i++)
    {
        scanf("%d", &m);
        p[i] = (int*)malloc(m*sizeof(int));
        for(k=j=0; j<m; j++)
        {
            scanf("%d",&x);
            start = 0;
            end = k - 1;
            while(start <= end)
            {
                mid = (start + end) >> 1;
                if(p[i][mid] < x)
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
            if(start != j && p[i][start] == x)
            {
                continue;
            }
            else
            {
                p[i][k] = x;
                x = k;
                while(x > start)
                {
                    swap(p[i]+x, p[i]+x-1);
                    x--;
                }
                k++;
            }
        }
        a[i] = k;
    }
    scanf("%d", &m);
    while(m--)
    {
        scanf("%d%d", &i, &j);
        x = common(p[i-1], a[i-1], p[j-1], a[j-1]);
        printf("%.1lf%%\n", x * 100.0 / (a[i - 1] + a[j - 1] - x));
    }
    for(i=0; i<n; i++)
    {
        free(p[i]);
    }
    free(p);
	return 0;
}