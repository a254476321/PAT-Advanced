#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n, m, i, j, a[1000];
    _Bool flag;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &m);
        flag = 1;
        for(i = 0; i < m && flag; i++)
        {
            scanf("%d", a + i);
            for(j = 0; j < i; j++)
            {
                if(a[i] == a[j] || i - j == a[i] - a[j])
                {
                    flag = 0;
                    puts("NO");
                    scanf("%*[^\n]");
                    break;
                }
            }
        }
        if(flag)
        {
            puts("YES");
        }
    }
    return 0;
}