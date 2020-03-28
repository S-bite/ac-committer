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
    int x, y, a, b, c;

    cin >> x >> y >> a >> b >> c;
    int x_ = x;
    int y_ = y;

    vector<ll> p(a), q(b), r(c);
    rep(i, a) cin >> p[i];
    rep(i, b) cin >> q[i];
    rep(i, c) cin >> r[i];
    sort(ALL(p), greater<ll>());
    sort(ALL(q), greater<ll>());
    rep(i, x) r.push_back(p[i]);
    rep(i, y) r.push_back(q[i]);
    sort(ALL(r), greater<ll>());
    ll ans = 0;
    rep(i, x + y)
    {
        ans += r[i];
    }
    cout << ans << endl;
    return 0;
}
