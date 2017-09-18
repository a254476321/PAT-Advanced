#include<stdio.h>
#include<string.h>
void replace(char a[])
{
    int i = 0;
    while(a[i] != '\0')
    {
        switch(a[i])
        {
        case '1':
            a[i] = '@';
            break;
        case '0':
            a[i] = '%';
            break;
        case 'l':
            a[i] = 'L';
            break;
        case 'O':
            a[i] = 'o';
			break;
        }
        i++;
    }
}
int main()
{
    int n, i;
	short sum;
    const char a[] = "01lO";
    scanf("%d", &n);
    char name[n][11], pass[n][11];
    sum = n;
    for(i=0; i<sum; i++)
    {
        scanf("%s%s", name[i], pass[i]);
        if(strpbrk(pass[i],a) == NULL)
        {
            i--;
            sum--;
        }
        else
        {
            replace(pass[i]);
        }
    }
    if(sum != 0)
    {
		printf("%d\n", sum);
        for(i=0; i<sum; i++)
        {
            printf("%s %s\n", name[i], pass[i]);
        }
    }
    else if(n == 1)
    {

        puts("There is 1 account and no account is modified");
    }
    else
    {
        printf("There are %d accounts and no account is modified", n);
    }
    return 0;
}