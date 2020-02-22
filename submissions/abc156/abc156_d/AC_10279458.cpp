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

ll mpow(ll base, ll num)
{
    if (num == 0)
        return 1;
    ll prev = mpow(base, num / 2);
    if (num % 2 == 0)
    {
        return (prev * prev) % MOD;
    }
    else
    {
        return ((prev * base) % MOD * prev) % MOD;
    }
}

ll com(ll n, ll b)
{
    ll frac = 1;
    ll div = 1;
    for (ll i = 0; i < b; i++)
    {
        frac *= (n - i);
        frac %= MOD;
        div *= (i + 1);
        div %= MOD;
    }
    return (frac * mpow(div, MOD - 2)) % MOD;
}

int main(int argc, char const *argv[])
{

    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = mpow(2, n) - 1;

    cerr << com(n, a) << " " << com(n, b) << endl;
    ans -= com(n, a);
    ans -= com(n, b);
    while (ans < 0)
        ans += MOD;
    cout << ans << endl;

    return 0;
}
