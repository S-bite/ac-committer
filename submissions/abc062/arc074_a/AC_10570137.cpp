#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
#define chmin(x, y) x = min(x, y);
using namespace std;

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;

int main(int argc, char const *argv[])
{
    ll h, w;
    cin >> h >> w;
    ll ans = INF;
    ll a, b, c;
    rep(i, 1, h)
    {
        a = w * i;
        b = w * ((h - i) / 2);
        c = w * ((h - i + 1) / 2);
        chmin(ans, max({a, b, c}) - min({a, b, c}));
    }
    rep(i, 1, w)
    {
        a = h * i;
        b = h * ((w - i) / 2);
        c = h * ((w - i + 1) / 2);
        chmin(ans, max({a, b, c}) - min({a, b, c}));
    }
    rep(i, 1, h)
    {
        a = w * i;
        b = (h - i) * (w / 2);
        c = (h - i) * ((w + 1) / 2);
        chmin(ans, max({a, b, c}) - min({a, b, c}));
    }
    rep(i, 1, w)
    {
        a = h * i;
        b = (w - i) * (h / 2);
        c = (w - i) * ((h + 1) / 2);
        chmin(ans, max({a, b, c}) - min({a, b, c}));
    }
    cout << ans << endl;

    return 0;
}
