#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char a[102], b[102], c[102], d[1002];
    short n, i, x, y, x2, y2, k1 = 0, k2 = 0;
    scanf("%hd%s%s", &n, a, b);
    x = strspn(a, "0.");
    if(a[x] == 0)
    {
        x2 = x - 1;
    }
    else
    {
        for(x2=0; a[x2]!=0&&a[x2]!='.'; x2++);
    }
    y = strspn(b, "0.");
    if(b[y] == 0)
    {
        y2 = y - 1;
    }
    else
    {
        for(y2=0; b[y2]!=0&&b[y2]!='.'; y2++);
    }
    for(i=x; a[i]!=0&&k1<n; i++)
    {
        if(isdigit(a[i]))
        {
           c[k1++] = a[i]; 
        }
    }
    if(k1 < n)
    {
        memset(c + k1, '0', n - k1);
    }
    for(i=y; b[i]!=0&&k2<n; i++)
    {
        if(isdigit(b[i]))
        {
           d[k2++] = b[i];
        }
    }
    if(k2 < n)
    {
        memset(d + k2, '0', n - k2);
    }
    c[n] = d[n] = 0;
    if(x2 - x == y2 - y  && strcmp(c, d) == 0)
    {
        printf("YES 0.%s*10^%hd", c, x < x2 ? x2 - x : x2 - x + 1);
    }
    else
    {
        printf("NO 0.%s*10^%hd 0.%s*10^%hd", c, x < x2 ? x2 - x : x2 - x + 1, d, y2 > y ? y2 - y : y2 - y + 1);
    }
}