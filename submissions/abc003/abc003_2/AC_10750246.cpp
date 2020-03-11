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
    string s, t;
    cin >> s >> t;
    map<int, bool> mp;
    mp['a'] = true;
    mp['t'] = true;
    mp['c'] = true;
    mp['o'] = true;
    mp['d'] = true;
    mp['e'] = true;
    mp['r'] = true;
    rep(i, s.size())
    {
        if ((s[i] == '@' && mp[t[i]]) || (t[i] == '@' && mp[s[i]]))
            continue;
        if (s[i] != t[i])
        {
            cout << "You will lose" << endl;
            return 0;
        }
    }
    cout << "You can win" << endl;
    return 0;
}