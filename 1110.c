#include<stdio.h>
#include<string.h>
void dfs(short index, const short a[][2], int c[])
{
    if(a[index][0] != -1)
    {
        c[a[index][0]] = (c[index] << 1) + 1;
        dfs(a[index][0], a, c);
    }
    if(a[index][1] != -1)
    {
        c[a[index][1]] = (c[index] << 1) + 2;
        dfs(a[index][1], a, c);
    }
}
int main()
{
    int n, i;
	scanf("%d", &n);
    int c[n];
    short a[n][2], root, leaf;
    _Bool b[n];
    char x[3], y[3];
    memset(b, 0, n);
    memset(a, 255, sizeof(a));
    for(i=0; i<n; i++)
    {
        scanf("%s %s", x, y);
        if(x[0] != '-')
        {
            sscanf(x, "%hd", a[i]);
            b[a[i][0]] = 1;
        }
        if(y[0] != '-')
        {
            sscanf(y, "%hd", a[i] + 1);
            b[a[i][1]] = 1;
        }
    }
    for(root=0; root<n; root++)
    {
        if(b[root] == 0)
        {
            break;
        }
    }
    c[root] = 0;
    dfs(root, a, c);
    for(i=0; i<n&&c[i]<n; i++)
    {
        if(c[i] == n - 1)
        {
            leaf = i++;
            break;
        }
    }
    for(; i<n&&c[i]<n; i++);
    if(i == n)
    {
        printf("YES %d", leaf);
    }
    else
    {
        printf("NO %d", root);
    }
	return 0;
}