#include<stdio.h>
#include<ctype.h>
#include<string.h>
int *in;
void p(int index,const int b[][2])
{
    static int i;
    if(index==-1) return;
    p(b[index][1],b);
    in[i++]=index;
    p(b[index][0],b);
}
int main()
{
	int n,i,end;
    char a[4];
    scanf("%d\n",&n);
    int b[n][2],queue[n],d[n];
    _Bool c[n];
    memset(c,0,sizeof(c));
    for(i=0;i<n;i++)
    {
        gets(a);
        if(isdigit(a[0]))
        {
            b[i][0]=a[0]-'0';
            c[b[i][0]]=1;
        }
        else {
             b[i][0]=-1;
        }
        if(isdigit(a[2]))
        {
            b[i][1]=a[2]-'0';
            c[b[i][1]]=1;
        }
        else {
             b[i][1]=-1;
        }
    }
    for(i=0;i<n;i++)
    {
        if(c[i]==0)
        {
            break;
        }
    }
    queue[0]=i;
    end=1;
    for(i=0;i<n;i++)
    {
        if(b[queue[i]][1]!=-1)
        {
            queue[end++]=b[queue[i]][1];
        }
        if(b[queue[i]][0]!=-1)
        {
            queue[end++]=b[queue[i]][0];
        }
    }
    printf("%d",queue[0]);
    for(i=1;i<n;i++)
    {
        printf(" %d",queue[i]);
    }
    in=d;
    p(queue[0],b);
    printf("\n%d",d[0]);
    for(i=1;i<n;i++)
    {
        printf(" %d",d[i]);
    }
	return 0;
}