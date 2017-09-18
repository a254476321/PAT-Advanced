#include <stdio.h>
#include<ctype.h>
int main()
{
	int n=0,i=0,j=0,flag;
	char a[81],b[80]={0},x;
	scanf("%s\n",a);
	x=getchar();
	while(a[i]!='\0')
	{
		if(x==a[i]){
			i++;
			x=getchar();
			continue;
		}
		flag=1;
		a[i]=toupper(a[i]);
		for(j=0;j<n;j++)
		{
			if(b[j]==a[i]){
				flag=0;
				break;
			}
		}
		if(flag){
			n++;
			b[j]=a[i];
		}
		i++;
	}
	puts(b);
    return 0;
}