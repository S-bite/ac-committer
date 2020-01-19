#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

int main(int argc, char const *argv[])
{
    int num[3] = {0};
    string v[3];
    rep(i, 3)
    {
        cin >> v[i];
    }
    int cur = 0;
    while (true)
    {
        if (num[cur] == v[cur].size())
        {
            cout << (char)('A' + cur) << endl;
            return 0;
        }
        num[cur]++;
        cur = v[cur][num[cur] - 1] - 'a';
    }
    return 0;
}
