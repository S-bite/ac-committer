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
    string s;
    cin >> s;
    int n = s.size();
    vector<int> l(n + 1), r(n + 1);

    int inc = 0;
    int dec = 0;
    int cur = 0;
    l[0] = 0;
    rep(i, n)
    {
        if (s[i] == '>')
        {
            inc = 0;
        }
        else
        {
            inc++;
        }
        l[i + 1] = inc;
    }
    r[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '>')
        {
            dec++;
        }
        else
        {
            dec = 0;
        }
        r[i] = dec;
    }
    ll ans = 0;
    rep(i, n + 1)
    {
        ans += max(l[i], r[i]);
    }
    cout << ans << endl;

    return 0;
}