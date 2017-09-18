#include<stdio.h>
#include<string.h>
int *in, *post, *level;
void pre(int root, int start, int end, int index)
{
    if(start > end) return;
    int i = start;
    while(post[root] != in[i]) i++;
    level[index] = post[root];
    pre(root - 1 - end + i, start, i - 1,(index << 1) + 1);
    pre(root - 1, i + 1, end, (index + 1) << 1);
}
int main()
{
	int n, i;
    scanf("%d", &n);
    i=(1 << n) - 1;
    int a[n], b[n], c[i > 100000 ? 100000 : i];
    memset(c, 255, sizeof(c));
    post = a;
    in = b;
    level = c;
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    for(i=0; i<n; i++)
    {
        scanf("%d", &b[i]);
    }
    n--;
    pre(n, 0, n, 0);
    for(i=0; i<n; i++)
    {
        if(level[i] ==- 1)
        {
            n++;
            continue;
        }
        printf("%d ", level[i]);
    }
    while(level[i] == -1) i++;
    printf("%d", level[i]);
	return 0;
}