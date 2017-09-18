#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct user{
    long id;
    short score, f_rank, l_rank, local;
};
bool cmp(user &a, user &b)
{
    return a.score != b.score ? a.score > b.score : a.id < b.id;
}
int main()
{
	short n, i, k, j;
    vector<user> v, v2;
    scanf("%hd", &n);
    for(j=1; j<=n; j++)
    {
        scanf("%hd", &k);
        v2.resize(k);
        for(i=0; i<k; i++)
        {
            scanf("%ld %hd", &v2[i].id, &v2[i].score);
            v2[i].local = j;
        }
        sort(v2.begin(), v2.end(), cmp);
        v2[0].l_rank = 1;
        for(i=1; i<k; i++)
        {
            v2[i].l_rank = v2[i].score == v2[i - 1].score ? v2[i - 1].l_rank : i + 1;
        }
        v.insert(v.end(), v2.begin(), v2.end());
    }
    sort(v.begin(), v.end(), cmp);
    k = v.size();
    v[0].f_rank = 1;
    printf("%d\n%013ld %hd %hd %hd\n", k, v[0].id, v[0].f_rank, v[0].local, v[0].l_rank);
    for(i=1; i<k; i++)
    {
        v[i].f_rank = v[i].score == v[i - 1].score ? v[i - 1].f_rank : i + 1;
        printf("%013ld %hd %hd %hd\n", v[i].id, v[i].f_rank, v[i].local, v[i].l_rank);
    }
	return 0;
}