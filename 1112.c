#include<stdio.h>

int main()
{
    int n, i;
	short a[123] = {0}, x = 0, k = 0;
    char s[1001], b[37];
    scanf("%d\n", &n);
    gets(s);
    for(i=0; s[i]!=0; i++)
    {
        if(a[(int)s[i]] != 1)
        {
            if(s[i] == s[i + 1])
            {
                x++;
            }
            else
            {
                if((x + 1) % n == 0)
                {
                    if(a[(int)s[i]] == 0)
                    {
                        b[k++] = s[i];
                    }
                    a[(int)s[i]] = -1;
                }
                else
                {
                    a[(int)s[i]] = 1;
                }
                x = 0;
            }
        }
    }
    for(i=0; i<k; i++)
    {
        if(a[(int)b[i]] == -1)
        {
            putchar(b[i]);
        }
    }
    putchar('\n');
    for(i=0; s[i]!=0; i++)
    {
        putchar(s[i]);
        if(a[(int)s[i]] != 1)
        {
            i += n - 1;
        }
    }
	return 0;
}