#include <stdio.h>
#include <math.h>
#include <string.h>
_Bool isPrime(short a)
{
    short max,i;
    if((a != 2 && (a & 1) == 0) || a == 1) return 0;
    max = sqrt(a);
    for(i=3; i<=max; i+=2)
    {
        if(a % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    short n, m, i, y;
    int x, j;
    scanf("%hd%hd", &n, &m);
    if(n == 1 ||(!isPrime(n) && (n & 1) == 0))
    {
        n++;
    }
    while(!isPrime(n))
    {
        n += 2;
    }
    _Bool b[n];
    memset(b, 0, n);
    for(i=1; i<m; i++)
    {
        scanf("%d", &x);
        y = x % n;
        if(b[y] == 0)
        {
            b[y] = 1;
            printf("%d ", y);
        }
        else
        {
            for(j=1; j<n; j++)
            {
                y = (x + j * j) % n;
                if(b[y] == 0)
                {
                    b[y] = 1;
                    printf("%d ", y);
                    break;
                }
            }
            if(j == n)
            {
                printf("- ");
            }
        }
    }
    scanf("%d", &x);
    y = x % n;
    if(b[y] == 0)
    {
        b[y] = 1;
        printf("%d", y);
    }
    else
    {
        for(j=1; j<n; j++)
        {
            y = (x + j * j) % n;
            if(b[y] == 0)
            {
                b[y] = 1;
                printf("%d", y);
                break;
            }
        }
        if(j == n)
        {
            printf("-");
        }
    }
	return 0;
}