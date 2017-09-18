#include <stdio.h>
int main()
{
    int a,b,c,x,y,z;
	scanf("%d.%d.%d%d.%d.%d",&a,&b,&c,&x,&y,&z);
    c+=z;
    b+=y+c/29;
    c%=29;
    a+=x+b/17;
    b%=17;
    printf("%d.%d.%d",a,b,c);
	return 0;
}