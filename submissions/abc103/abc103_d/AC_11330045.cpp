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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(m);
    rep(i, m)
    {
        cin >> v[i].second >> v[i].first;
        v[i].first--;
        v[i].second--;
    }
    sort(ALL(v));
    int cur = 0;
    int ans = 0;
    while (cur < m)
    {
        int end = v[cur].first;
        // cerr << end << endl;
        while (cur < m && v[cur].second < end)
        {
            cur++;
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}