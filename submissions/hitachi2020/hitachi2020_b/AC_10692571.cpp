#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;
map<int, int> ans;
map<int, vector<int>> g;
int main()
{
    int a, b, m;
    cin >> a >> b >> m;
    vector<int> v1(a), v2(b);
    rep(i, a)
    {
        cin >> v1[i];
    }
    rep(i, b)
    {
        cin >> v2[i];
    }
    ll ans = INF;
    rep(i, m)
    {
        int x, y, c;
        cin >> x >> y >> c;
        x--;
        y--;
        ans = min(ans, (ll)v1[x] + v2[y] - c);
    }
    sort(ALL(v1));
    sort(ALL(v2));
    ans = min(ans, (ll)v1[0] + v2[0]);
    cout << ans << endl;

    return 0;
}