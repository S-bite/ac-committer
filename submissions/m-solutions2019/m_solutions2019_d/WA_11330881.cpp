#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

map<int, vector<int>> g;

int main()
{
    int n;
    cin >> n;
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> c(n);
    rep(i, n) cin >> c[i];
    sort(ALL(c), greater<int>());
    vector<pair<int, int>> deg(n);
    rep(i, n)
    {
        deg[i].first = g[i].size();
        deg[i].second = i;
    }
    sort(ALL(deg), greater<pair<int, int>>());
    map<int, int> mp;
    rep(i, n)
    {
        mp[deg[i].second] = c[i];
    }
    ll ans = 0;
    rep(i, n)
    {
        for (auto x : g[i])
        {
            if (x > i)
            {
                ans += min(mp[i], mp[x]);
            }
        }
    }
    cout << ans << endl;
    rep(i, n) cout << mp[i] << " ";
    cout << endl;

    return 0;
}