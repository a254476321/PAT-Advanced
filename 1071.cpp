#include <iostream>
#include <map>
#include <algorithm>
#include <sstream>
#include <cctype>
using namespace std;
int trans(int a)
{
    if(isupper(a))
    {
        return a | 32;
    }
    else if(isalnum(a))
    {
        return a;
    }
    return ' ';
}
int main()
{
    int max = 0;
    map<string, int> m;
	string a;
    getline(cin, a);
    transform(a.begin(), a.end(), a.begin(), trans);
    stringstream stream(a);
    while(stream >> a)
    {
        m[a]++;
    }
    for(map<string, int>::iterator it=m.begin(); it!=m.end(); it++)
    {
        if(it->second > max)
        {
            max = it->second;
            a = it->first;
        }
        else if(it->second == max && a > it->first)
        {
            a = it->first;
        }
    }
    printf("%s %d", a.c_str(), max);
	return 0;
}