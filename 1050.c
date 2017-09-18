#include<stdio.h>
int main()
{
    int i;
	char a[10001];
    _Bool b[127] = {0};
    gets(a);
    while((i = getchar()) != '\n')
    {
        b[i] = 1;
    }
    for(i=0; a[i]!='\0'; i++)
    {
        if(b[(int)a[i]] != 1)
        {
            putchar(a[i]);
        }
    }
	return 0;
}