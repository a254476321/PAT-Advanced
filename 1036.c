#include<stdio.h>
typedef struct stu{
    char name[11],id[11];
} STU;
int main()
{
	int n,grade,mgrade=101,fgrade=-1,m,f,i;
    char sex;
    scanf("%d",&n);
    STU s[n];
    for(i=0;i<n;i++)
    {
        scanf("%s %c %s%d",s[i].name,&sex,s[i].id,&grade);
        if(sex=='M')
        {
            if(grade<mgrade)
            {
                m=i;
                mgrade=grade;
            }
        }
        else
        {
            if(grade>fgrade)
            {
                f=i;
                fgrade=grade;
            }
        }
    }
    if(fgrade==-1)
    {
        puts("Absent");
    }
    else
    {
        printf("%s %s\n",s[f].name,s[f].id);
    }
    if(mgrade==101)
    {
        puts("Absent");
    }
    else
    {
        printf("%s %s\n",s[m].name,s[m].id);
    }
    if(fgrade==-1||mgrade==101)
    {
        puts("NA");
    }
    else
    {
        printf("%d",fgrade-mgrade);
    }
	return 0;
}