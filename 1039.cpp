#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n, i, j;
    short m, a, b, c, d;
    vector<short> v[26][26][26][10];
    char s[5];
    scanf("%d%hd", &n, &m);
    while(m--)
    {
        scanf("%d%d", &i, &j);
        while(j--)
        {
            scanf("%s", s);
            v[s[0] - 65][s[1] - 65][s[2] - 65][s[3] - 48].push_back(i);
        }
    }
    while(n--)
    {
        scanf("%s", s);
        a = s[0] - 65;
        b = s[1] - 65;
        c = s[2] - 65;
        d = s[3] - 48;
        sort(v[a][b][c][d].begin(), v[a][b][c][d].end());
        j = v[a][b][c][d].size();
        printf("%s %d", s, j);
        for(i=0; i<j; i++)
        {
            printf(" %d", v[a][b][c][d][i]);
        }
        putchar('\n');
    }
	return 0;
}