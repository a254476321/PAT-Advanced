#include <stdio.h>
void p(short a,_Bool b)
{
	if(a>=10) p(a/10,1);
	switch(a%10)
	{
		case 0:printf("zero"); break;
		case 1:printf("one"); break;
		case 2:printf("two"); break;
		case 3:printf("three"); break;
		case 4:printf("four"); break;
		case 5:printf("five"); break;
		case 6:printf("six"); break;
		case 7:printf("seven"); break;
		case 8:printf("eight"); break;
		default:printf("nine");
	}
	if(b) printf(" ");
}
int main()
{
	short sum=0;
	char x;
	while('\n'!=(x=getchar()))
	{
		sum+=x-'0';
	}
	p(sum,0);
	return 0;
}