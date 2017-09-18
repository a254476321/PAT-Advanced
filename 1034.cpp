#include<iostream>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
bool cmp(const string &a, const string &b)
{
    return a < b;
}
short search(short x, short a[])
{
    return a[x] == -1 ? x : (a[x] = search(a[x], a));
}
bool combine(short x, short y, short a[])
{
    if(x == y)
    {
        return 0;
    }
    else
    {
        a[y] = x;
        return 1;
    }
}
int main()
{
    string s1, s2;
	int n, k, i, x, y, m = 1;
    map<string, int> c;
    scanf("%d%d", &n, &k);
    i = n << 1;
    string b[i + 1], f[n / 3];
    short min[i], a[i], d[n][2], pepl[i + 1];
    int total[i + 1];
    fill(a, a + i, -1);
    fill(pepl, pepl + i + 1, 0);
    fill(total, total + i + 1, 0);
    for(i=0; i<n; i++)
    {
        cin >> s1 >> s2 >> x;
        if(c[s1] == 0)
        {
            c[s1] = d[i][0] = m;
            b[m] = s1;
            min[m++] = x;
        }
        else
        {
            d[i][0] = c[s1];
            min[d[i][0]] += x;
        }
        if(c[s2] == 0)
        {
            b[m] = s2;
            c[s2]= d[i][1] = m;
            min[m++] = x;
        }
        else
        {
            d[i][1] = c[s2];
            min[d[i][1]] += x;
        }
    }
    for(i=0; i<n; i++)
    {
        x = search(d[i][0], a);
        y = search(d[i][1], a);
        if(min[x] < min[y])
        {
            x ^= y;
            y ^= x;
            x ^= y;
        }
        if(combine(x, y, a))
        {
            pepl[x] += pepl[y] + 1;
            total[x] += total[y] + min[y];
            pepl[y] = 0;
        }
    }
    k <<= 1;
    x = 0;
    for(i=1; i<m; i++)
    {
        if(pepl[i] > 1 && total[i] + min[i] > k)
        {
            f[x++] = b[i];
        }
    }
    sort(f, f + x, cmp);
    cout << x << endl;
    for(i=0; i<x; i++)
    {
        cout << f[i] << ' ' << pepl[c[f[i]]] + 1 << endl;
    }
	return 0;
}