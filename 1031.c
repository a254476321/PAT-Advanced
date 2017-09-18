#include<stdio.h>
#include<string.h>
void p(int i)
{
    while(i--) putchar(' ');
}
int main()
{
    char a[81];
    int i,n,x,y;
    gets(a);
    n=strlen(a);
    x=(n+2)/3;
    y=n-(x<<1);
    for(i=0;i<x-1;i++)
    {
        putchar(a[i]);
        p(y);
        putchar(a[n-1-i]);
        putchar('\n');
    }
    a[n-i]=0;
    puts(a+i);
	return 0;
}