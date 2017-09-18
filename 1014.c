#include<stdio.h>
#include<string.h>
void addTime(char a[],const char b[],int c)
{
    int h,m;
    if(b[0]=='S'||strcmp(b,"16:59")>0)
    {
        strcpy(a,"Sorry");
        return;
    }
    sscanf(b,"%d:%d",&h,&m);
    m+=c;
    h+=m/60;
    m%=60;
    sprintf(a,"%02d:%02d",h,m);
}
int main()
{
    int n,m,k,q,i,j,o,min;
    scanf("%d%d%d%d",&n,&m,&k,&q);
    int p[k+1],last[n],next[k+1],first[n];
    char t[k+1][6],temp[6];
    memset(next,0,sizeof(next));
    for(i=0; i<k; i++)
    {
        scanf("%d",&p[i+1]);
    }
    o=1;
    for(i=0; i<n&&o<=k; i++)
    {
        addTime(t[o],"08:00",p[i+1]);
        first[i]=o;
        last[i]=o++;
    }
    for(i=1; i<m&&o<=k; i++)
    {
        for(j=0; j<n&&o<=k; j++)
        {
            next[last[j]]=o;
            last[j]=o++;
        }
    }
    if(k>n)
    {
        while(1)
        {
            min=0;
            if(next[first[0]]==0)
            {
                strcpy(temp,"T");
            }
            else strcpy(temp,t[first[0]]);
            for(i=1; i<n; i++)
            {
                if(next[first[i]]!=0&&strcmp(temp,t[first[i]])>0)
                {
                    min=i;
                    strcpy(temp,t[first[i]]);
                }
            }
            j=next[first[min]];
            if(j==0) break;
            addTime(t[j],t[first[min]],p[j]);
            first[min]=j;
            if(o<=k)
            {
                next[last[min]]=o;
                last[min]=o++;
            }
        }
    }
    for(i=0; i<q; i++)
    {
        scanf("%d",&j);
        puts(t[j]);
    }
    return 0;
}