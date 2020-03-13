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
    int n;
    cin >> n;
    vector<int> a, b;
    vector<int> v;
    rep(i, n)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    auto w = v;
    sort(ALL(v));
    map<int, int> mp;
    rep(i, n) mp[v[i]] = i;
    rep(i, n)
    {
        if (i % 2 == 0)
        {
            a.push_back(mp[w[i]]);
        }
        else
        {
            b.push_back(mp[w[i]]);
        }
    }
    sort(ALL(a));
    sort(ALL(b));
    vector<int> c;
    rep(i, n)
    {
        if (i % 2 == 0)
        {
            c.push_back(a[i / 2]);
        }
        else
        {
            c.push_back(b[i / 2]);
        }
    }
    ll ans = 0;
    rep(i, n)
    {
        if (i < c[i])
        {
            ans += c[i] - i;
        }
    }
    cout << ans << endl;

    return 0;
}
