#include<stdio.h > 
#include<string.h > 
void p(int index, const int a[])
{
    if(a[index-1] == 0) return;
    p(index << 1, a);
    p((index << 1) + 1, a);
    printf("%d ", a[index - 1]);
}
int main()
{
	int n, cur = 1, m = 0, x;
    char a[5];
    scanf("%d", &n);
    x = 1 << n;
    int stack[x > 100000 ? 100000 : x];
    memset(stack, 0, sizeof(stack));
    while(1)
    {
        scanf("%s", a);
        if(a[1] == 'u')
        {
            scanf("%d", &x);
            stack[cur - 1] = x;
            cur <<= 1;
            m++;
        }
        else
        {
            if((cur & 1) == 0)
            {
                cur++;
            }
            else
            {
                if(m == n) break;
                cur >>=1;
                while((cur & 1) == 1) cur >>=1;
                cur++;
            }
        }
    }
    if(n > 1) p(2, stack);
    if(n > 2 || (n == 2 && stack[1] == 0)) p(3, stack);
    printf("%d", stack[0]);
	return 0;
}