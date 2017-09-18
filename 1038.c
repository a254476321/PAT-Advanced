#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int arrcmp(const char a[], const char b[])
{
    if(a[0] != b[0] || strlen(a) == strlen(b))
    {
        return strcmp(a, b);
    }
    else
    {
        char x[17], y[17];
        x[0] = y[0] = 0;
        strcat(x, a);
        strcat(x, b);
        strcat(y, b);
        strcat(y, a);
        return strcmp(x, y);
    }
}
int cmp(const void *a, const void *b)
{
    return arrcmp(a, b);
}
int main()
{
    int n, i;
	scanf("%d", &n);
    char a[n][9];
    for(i=0; i<n; i++)
    {
        scanf("%s", a[i]);
    }
    qsort(a, n, sizeof(a[0]), cmp);
    sscanf(a[n - 1], "%d", &i);
    if(i == 0)
    {
        putchar('0');
        return 0;
    }
    for(i=0; a[0][i]=='0'; i++);
    printf("%s", a[0] + i);
    for(i=1; i<n; i++)
    {
        printf("%s", a[i]);
    }
	return 0;
}