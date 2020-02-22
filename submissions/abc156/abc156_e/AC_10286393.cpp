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

const int MAX = 510000;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll calc(ll n)
{
    ll frac = 1;
    ll div = 1;
    rep(i, n - 1)
    {
        frac *= (n + 1 + i);
        frac %= MOD;
    }
    rep(i, n - 1)
    {
        div *= (n - 1 - i);
        div %= MOD;
    }
    cerr << frac << " " << div << endl;
    return (frac * mpow(div, MOD - 2)) % MOD;
}

int main(int argc, char const *argv[])
{
    ll n, k;
    cin >> n >> k;
    COMinit();
    assert(COM(n, 1) == n);
    if (k > n - 1)
        k = n - 1;
    ll ans = calc(n);
    //cerr << ans << endl;
    for (ll i = n - 1; i > k; i--)
    {
        ll j = n - i;
        ans -= (COM(n, j) * COM(n - 1, j - 1)) % MOD;
        //cerr << COM(n, j) << " " << COM(n - 1, j - 1) << endl;
        if (ans < 0)
            ans += MOD;
        //cerr << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
