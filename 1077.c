#include<stdio.h>
#include<string.h>
int main()
{
	int n, i, j, bn;
    char a[257], b[257];
    scanf("%d\n", &n);
    gets(b);
    bn = strlen(b);
    while(--n)
    {
        gets(a);
        i = strlen(a) - 1;
        j = bn - 1;
        while(i > -1 && j > -1 && a[i] == b[j])
        {
            i--;
            j--;
        }
        if(j == -1)
        {
            continue;
        }
        sprintf(b, "%s", a + i + 1);
        if((bn = strlen(b)) == 0)
        {
            puts("nai");
            return 0;
        }
    }
    puts(b);
	return 0;
}