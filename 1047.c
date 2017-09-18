#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void *a, const void *b)
{
    return strcmp(a, b);
}
char a[2501][400][5];
int main()
{
	unsigned short n, i;
    short m, j, k;
    scanf("%hu%hd", &n, &m);
    char s[5];
    unsigned short b[n];
    memset(b, 0, n << 1);
    for(i=0; i<n; i++)
    {
        scanf("%s%hd", s, &j);
        while(j--)
        {
            scanf("%hd", &k);
            strcpy(a[k][b[k]++], s);
        }
    }
    for(j=1; j<=m; j++)
    {
        printf("%hd %hu\n", j, b[j]);
        qsort(a[j], b[j], 5, cmp);
        for(i=0; i<b[j]; i++)
        {
            puts(a[j][i]);
        }
    }
	return 0;
}