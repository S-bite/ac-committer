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
ll a, b, c, d, e, n, h;

bool isok(ll x, ll y)
{
    ll z = n - x - y;
    return h + b * x + d * y - e * z > 0;
}

ll binsearch(ll x)
{
    ll l = -1;
    ll r = n - x;
    while (l + 1 != r)
    {
        ll mid = (l + r) / 2;
        if (isok(x, mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    return r;
}

int main()
{
    cin >> n >> h >> a >> b >> c >> d >> e;
    ll ans = INF;
    rep(i, n)
    {
        ll cur = a * i + c * binsearch(i);
        ans = min(ans, cur);
    }
    cout << ans << endl;
    return 0;
}