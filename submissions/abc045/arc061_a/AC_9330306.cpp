#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

ll calc(vector<int> &v, int bit)
{
    ll ret = 0;
    ll tmp = v[0];
    rep(i, v.size() - 1)
    {
        if (((bit >> i) & 1) == 1)
        {
            ret += tmp;
            tmp = v[i + 1];
        }
        else
        {
            tmp *= 10;
            tmp += v[i + 1];
        }
    }
    ret += tmp;
    return ret;
}

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    vector<int> v(s.size());
    ll ans = 0;
    rep(i, s.size())
    {
        v[i] = s[i] - '0';
    }
    rep(i, (1 << (v.size() - 1)))
    {
        ans += calc(v, i);
    }
    cout << ans << endl;
    return 0;
}
