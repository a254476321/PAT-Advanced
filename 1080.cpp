#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
struct stu{
    unsigned short id, rank;
    short gi, ge, fg;
};
bool cmp(stu &a, stu &b)
{
    return a.fg != b.fg ? a.fg > b.fg : a.ge > b.ge;
}
int main()
{
    unsigned short n, i;
    short m, k, j, x;
    scanf("%hu%hd%hd", &n, &m, &k);
    unsigned short num[m], rank[m] = {0};
    set<unsigned short> v[m];
    short sel[n][k];
    bool seled[n] = {0};
    stu s[n];
    for(i=0; i<m; i++)
    {
        scanf("%hu", num + i);
    }
    for(i=0; i<n; i++)
    {
        scanf("%hd%hd", &s[i].ge, &s[i].gi);
        s[i].fg = (s[i].ge + s[i].gi) >> 1;
        s[i].id = i;
        for(j=0; j<k; j++)
        {
            scanf("%hd", sel[i] + j);
        }
    }
    sort(s, s + n, cmp);
    s[0].rank = 1;
    for(i=1; i<n; i++)
    {
        s[i].rank = s[i].fg == s[i - 1].fg && s[i].ge == s[i - 1].ge ? s[i - 1].rank : i + 1;
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<k; j++)
        {
            if(seled[s[i].id])
            {
                continue;
            }
            x = sel[s[i].id][j];
            if(num[x] > v[x].size())
            {
                v[x].insert(s[i].id);
                rank[x] = s[i].rank;
                seled[s[i].id] = 1;
            }
            else if(rank[x] == s[i].rank)
            {
                v[x].insert(s[i].id);
                seled[s[i].id] = 1;
            }
        }
    }
    set<unsigned short>::iterator it;
    for(j=0; j<m; j++)
    {
        n = v[j].size();
        if(n != 0)
        {
            it = v[j].begin();
            printf("%hu", *it++);
            for(; it!=v[j].end(); it++)
            {
                printf(" %hu", *it);
            }
        }
        putchar('\n');
    }
	return 0;
}