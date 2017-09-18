#include<stdio.h>
int p(double *sum)
{
    double a,b,c,max;
    int i;
    scanf("%lf%lf%lf",&a,&b,&c);
    if(b>a)
    {
        i=1;
        max=b;
    }
    else{
        max=a;
        i=0;
    }
    if(c>max)
    {
        i=2;
        max=c;
    }
    *sum*=max;
    return i;
}
int main()
{
    char s[]={'W','T','L'};
	double sum=1;
    printf("%c ",s[p(&sum)]);
    printf("%c ",s[p(&sum)]);
    printf("%c ",s[p(&sum)]);
    sum=(sum*0.65-1)*2;
    printf("%.2lf",sum);
}