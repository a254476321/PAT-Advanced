#include<stdio.h>
#include<string.h>
int main()
{
	int n, k, i, j, x, y, m, inf;
	short a[26][26][26];
	char s[4], s2[4];
	scanf("%d%d", &n, &k);
	int e[n][n], dis[n], happy[n], h[n];
	short b[n][3], num[n], bf[n], deep[n];
	_Bool book[n];
	memset(e, 6, sizeof(e));
	memset(book, 0, n);
	memset(bf, 0, sizeof(bf));
	inf = e[0][0];
	scanf("%s", s);
	b[0][0] = s[0] - 65;
	b[0][1] = s[1] - 65;
	b[0][2] = s[2] - 65;
	a[b[0][0]][b[0][1]][b[0][2]] = 0;
	for(i=1; i<n; i++)
	{
		deep[i] = 1;
		num[i] = 1;
		scanf("%s%d", s, &x);
		b[i][0] = s[0] - 65;
		b[i][1] = s[1] - 65;
		b[i][2] = s[2] - 65;
		a[b[i][0]][b[i][1]][b[i][2]] = i;
		happy[i] = h[i] = x;
	}
	for(i=0; i<k; i++)
	{
		scanf("%s%s%d", s, s2, &m);
		x = a[s[0] - 65][s[1] - 65][s[2] - 65];
		y = a[s2[0] - 65][s2[1] - 65][s2[2] - 65];
		e[x][y] = m;
		e[y][x] = m;
	}
	m = a[17][14][12];
	memcpy(dis, e[0], sizeof(e[0]));
	for(i=1; i<n; i++)
	{
		y = inf;
		for(j=1; j<n; j++)
		{
			if(!book[j] && dis[j] < y)
			{
				y = dis[j];
				x = j;
			}
		}
		if(y > dis[m])
		{
			break;
		}
		book[x] = 1;
		for(j=1; j<n; j++)
		{
			if(!book[j] && e[x][j] < inf)
			{
				y = dis[x] + e[x][j];
				if(y < dis[j])
				{
					dis[j] = y;
					num[j] = num[x];
					bf[j] = x;
					h[j] = h[x] + happy[j];
					deep[j] = deep[x] + 1;
				}
				else if(y == dis[j])
				{
					num[j] += num[x];
					y = h[x] + happy[j];
					if(y > h[j])
					{
						h[j] = y;
						bf[j] = x;
						deep[j] = deep[x] + 1;
					}
					else if(y == h[j] && deep[x] + 1 < deep[j])
					{
						bf[j] = x;
						deep[j] = deep[x] + 1;
					}
				}
			}
		}
	}
	printf("%d %d %d %d\n", num[m], dis[m], h[m], h[m] / deep[m]);
	k = deep[m] - 1;
	for(i=0; i<k; i++)
	{
		m = bf[m];
		happy[i] = m;
	}
	printf("%c%c%c", b[0][0] + 65, b[0][1] + 65, b[0][2] + 65);
	while(i--)
	{
		x = happy[i];
		printf("->%c%c%c", b[x][0] + 65, b[x][1] + 65, b[x][2] + 65);
	}
	puts("->ROM");
	return 0;
}