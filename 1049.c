#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    const int s[] = {0, 1, 20, 300, 4000, 50000, 600000, 7000000, 80000000, 900000000};
    int n, i, sum = 0, x, y;
    char a[11];
    gets(a);
    n = strlen(a) - 1;
    x = pow(10, n);
    for(i=0; x!=1; i++)
    {
        if(a[i] == '0') {}
        else if (a[i] != '1')
        {
            sum += x + s[n - i] * (a[i] - '0');
        }
        else
        {
            sscanf(a + i + 1, "%d", &y);
            sum += y + 1 + s[n - i];
        }
        x /= 10;
    }
    if(a[i] > '0')
    {
        sum++;
    }
    printf("%d", sum);
    return 0;
}