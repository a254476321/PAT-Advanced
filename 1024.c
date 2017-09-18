#include<stdio.h>
#include<string.h>
void rev(char a[],short n)
{
    short i = 0, m = n >> 1;
    n--;
    while(i < m)
    {
        a[i] ^= a[n - i];
        a[n - i] ^= a[i];
        a[i] ^= a[n - i];
        i++;
    }
}
_Bool isPal(char a[],short n)
{
    short i = 0, m = n >> 1;
    n--;
    while(i < m)
    {
        if(a[i] != a[n - i])
        {
            return 0;
        }
        i++;
    }
    return 1;
}
void add(char a[], short n)
{
    short i = 0, m = (n + 1) >> 1;
    n--;
    while(i < m)
    {
        a[i] = a[n - i] = a[i] + a[n - i] - '0';
        i++;
    }
    n++;
    for(i=0; i<n; i++)
    {
        if(a[i] > '9')
        {
            a[i] -= 10;
            a[i + 1]++;
        }
    }
    if(a[n] == 1)
    {
        a[n] = '1';
    }
}
int main()
{
    int k, i, j;
    char a[60] = {0};
    scanf("%s%d", a, &k);
    for(i=0; i<k; i++)
    {
        j = strlen(a);
        if(isPal(a, j))
        {
            break;
        }
        add(a, j);
    }
    if(i == k)
	{
		rev(a, strlen(a));
	}
    printf("%s\n%d", a, i);
    return 0;
}