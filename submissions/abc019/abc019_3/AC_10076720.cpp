#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, bool> mp;
    rep(i, n)
    {
        int a;
        cin >> a;
        while (a % 2 == 0)
            a /= 2;
        mp[a] = true;
    }
    cout << mp.size() << endl;
    return 0;
}