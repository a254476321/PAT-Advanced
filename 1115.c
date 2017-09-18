#include<stdio.h>
#include<string.h>
short max(short a, short b)
{
    return a > b ? a : b;
}
int main()
{
	int n, i, j, start, end, mid;
    short level[2001] = {0}, *p = level + 1000, m = 0, same[2001] = {0}, *p2= same + 1000;;
    scanf("%d",&n);
    int a[n];
    short b[n];
    memset(b, 0, sizeof(b));
    scanf("%d",a);
    b[0]++;
    for(i=1; i<n; i++)
    {
        scanf("%d", a + i);
        start = 0;
        end = i - 1;
        while(start <= end)
        {
            mid = (start + end) >> 1;
            if(a[mid] < a[i])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        if(i != start && a[i] == a[start])
        {
            mid = max(p2[a[i]] == 0 ? p[a[i]] + 1 : p2[a[i]] + 1, start == 0 ? -1 : p[a[start - 1]] + 1);
            b[mid]++;
            p2[a[i]] = mid;
        }
        else
        {
            mid = p[a[i]] = max(p2[a[start]] == 0 ? p[a[start]] + 1 : p2[a[start]] + 1, start == 0 ? -1 : p[a[start - 1]] + 1);
            b[mid]++;
        }
        if(mid > m)
        {
            m = mid;
        }
        j = i;
        while(j > start)
        {
            a[j - 1] ^= a[j];
            a[j] ^= a[j - 1];
            a[j - 1] ^= a[j];
            j--;
        }
    }
    printf("%d + %d = %d", b[m], b[m - 1], b[m] + b[m - 1]);
	return 0;
}