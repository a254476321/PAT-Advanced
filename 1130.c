#include<stdio.h>
#include<string.h>
void p(const char a[][11],const int b[][2],int index)
{
    static _Bool i;
    if(index==-1) return;
    index--;
    if(i&&!(b[index][0]==-1&&b[index][1]==-1))
    {
        putchar('(');
        p(a,b,b[index][0]);
        printf("%s",a[index]);
        p(a,b,b[index][1]);
        putchar(')');
    }
    else
    {
        i=1;
        p(a,b,b[index][0]);
        printf("%s",a[index]);
        p(a,b,b[index][1]);
    }
}
int main()
{
	int n,i;
    scanf("%d",&n);
    char a[n][11];
    int b[n][2];
    _Bool c[n+1];
    memset(c,0,sizeof(c));
    for(i=0;i<n;i++)
    {
        scanf("%s%d%d",a[i],b[i],b[i]+1);
        c[b[i][0]]=c[b[i][1]]=1;
    }
    for(i=1;i<n;i++)
    {
        if(c[i]==0) break;
    }
    p(a,b,i);
	return 0;
}