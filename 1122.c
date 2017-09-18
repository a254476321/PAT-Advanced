#include<stdio.h>
#include<string.h>
int main()
{
	int n, m, i, x, y, k, first;
	scanf("%d%d", &n, &m);
    _Bool a[n + 1][n + 1], b[n + 1];
    memset(a, 0, sizeof(a));
    while(m--)
    {
        scanf("%d%d", &x, &y);
        a[x][y] = a[y][x] = 1;
    }
    scanf("%d", &m);
    while(m--)
    {
        scanf("%d", &k);
        if(k != n + 1)
        {
            scanf("%*[^\n]");
            puts("NO");
            continue;
        }
        memset(b + 1, 0, n);
        scanf("%d", &first);
        x = first;
        b[x] = 1;
        for(i=1; i<n; i++)
        {
            scanf("%d", &y);
            if(a[x][y] && b[y] == 0)
            {
                x = y;
                b[x] = 1;
            }
            else
            {
                break;
            }
        }
        if(i != n)
        {
            scanf("%*[^\n]");
            puts("NO");
            continue;
        }
        scanf("%d", &y);
        if(first != y || a[x][y] == 0)
        {
            puts("NO");
        }
        else
        {
            puts("YES");
        }
    }
	return 0;
}