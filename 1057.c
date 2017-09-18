#include<stdio.h>
void add(int v, int a[])
{
    for(int i=v; i<100001; i += i&-i)
    {
        a[i]++;
    }
}
void minus(int v, int a[])
{
    for(int i=v; i<100001; i += i&-i)
    {
        a[i]--;
    }
}
int getIndex(int x, const int a[])
{
    int sum = 0, i;
    for(i=x; i>0; i -= i&-i)
    {
        sum += a[i];
    }
    return sum;
}
void getMedian(int max, int n, const int a[])
{
    int low = 0, high = max, mid;
    while(low <= high)
    {
        mid = (low + high) >> 1;
        if(getIndex(mid, a) < n)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    printf("%d\n", low);
}
int main()
{
    int n, c[100001] = {0}, max = 0, x, stack[100001], k = 0;
    char a[12];
    scanf("%d\n", &n);
    while(n--)
    {
        gets(a);
        switch(a[1])
        {
            case 'u':
                sscanf(a, "%*s%d", &x);
                if(x > max)
                {
                    max = x;
                }
                add(x, c);
                stack[k++] = x;
                break;
            case 'o':
                if(k == 0)
                {
                    puts("Invalid");
                }
                else
                {
                    minus(stack[--k], c);
                    printf("%d\n", stack[k]);
                }
                break;
            default:
                if(k==0)
                {
                    puts("Invalid");
                }
                else
                {
                    getMedian(max, (k + 1) >> 1, c);
                }
        }
    }
	return 0;
}