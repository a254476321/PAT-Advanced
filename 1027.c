#include<stdio.h>
int main()
{
    const char a[]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
    int x;
    scanf("%d",&x);
    printf("#%c%c",a[x/13],a[x%13]);
    scanf("%d",&x);
    printf("%c%c",a[x/13],a[x%13]);
    scanf("%d",&x);
    printf("%c%c",a[x/13],a[x%13]);
	return 0;
}