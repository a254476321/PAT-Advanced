#include<stdio.h>
#include<string.h>
int main()
{
    const char num[][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"},
    w[][6] = {" Qian", "", " Shi", " Bai"};
	char a[11];
    int x;
    short n, i, j, k, b[4] = {0};
	scanf("%d", &x);
    if(x < 0)
    {
        printf("Fu ");
        x = -x;
    }
    sprintf(a, "%d", x);
    n = strlen(a);
    j = 0;
    for(i=0; i<n; i++)
    {
        if(a[i] == '0')
        {
            k = i;
            while(a[i + 1] == '0')
            {
                i++;
            }
            b[j++] = i - k;
        }
    }
    printf("%s%s", num[a[0] - 48], w[n & 3]);
    if(n == 9)
    {
        printf(" Yi");
    }
    else if(n == 5)
    {
        printf(" Wan");
    }
    k = 0;
    for(i=1; i<n; i++)
    {
        if(a[i] == '0')
        {
            if(n - i > 4 && n - i < 8 && n - i - b[k] < 6)
            {
                printf(" Wan");
            }
            i += b[k++];
            if(i != n - 1)
            {
                printf(" ling");
            }
        }
        else
        {
            printf(" %s%s", num[a[i] - '0'], w[(n - i) & 3]);
            if(n - i == 5)
            {
                printf(" Wan");
            }
        }
    }
	return 0;
}