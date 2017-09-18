#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
short max_deep;
vector<short> v;
bool *visit;

void dfs(short index, short deep,const vector<short> a[])
{
    visit[index] = 1;
    if(deep > max_deep)
    {
        max_deep = deep;
        v.clear();
        v.push_back(index);
    }
    else if(deep == max_deep)
    {
        v.push_back(index);
    }
    for(short x : a[index])
    {
        if(visit[x] == 0)
        {
            dfs(x, deep + 1, a);
        }
    }
}
int main()
{
    short n, i, x, y, count = 0;
    scanf("%hd", &n);
    vector<short> relate[n + 1];
    set<short> s;
    v.reserve(n);
    bool a[n + 1] = {0};
    visit = a;
    for(i=1; i<n; i++)
    {
        scanf("%hd%hd", &x, &y);
        relate[x].push_back(y);
        relate[y].push_back(x);
    }
    for(i=1; i<=n; i++)
    {
        if(a[i] == 0)
        {
            dfs(i, 0, relate);
            count++;
        }
    }
    if(count == 1)
    {
        fill(a + 1, a + n + 1, 0);
        x = v.back();
        for(vector<short>::iterator it=v.begin(); it!=v.end(); it++)
        {
            s.insert(*it);
        }
        v.clear();
        dfs(x, 0, relate);
        for(vector<short>::iterator it=v.begin(); it!=v.end(); it++)
        {
            s.insert(*it);
        }
        for(set<short>::iterator it=s.begin(); it!=s.end(); it++)
        {
            printf("%hd\n", *it);
        }
    }
    else
    {
        printf("Error: %d components", count);
    }
	return 0;
}