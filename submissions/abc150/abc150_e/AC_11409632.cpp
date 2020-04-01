#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

const int MAX = 510000;
const int MOD = 1000000007;

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

ll mpow(ll base, ll n)
{
    if (n == 0)
        return 1;
    ll prev = mpow(base, n / 2);
    if (n % 2 == 1)
    {
        return (prev * prev * base) % MOD;
    }
    else
    {
        return (prev * prev) % MOD;
    }
}

int main()
{
    // 前処理
    COMinit();
    int n;
    cin >> n;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];
    sort(ALL(v));
    ll ans = 0;
    rep(i, n)
    {
        ll tmp = v[i];
        int x = n - i - 1;
        if (x != 0)
        {

            tmp *= mpow(2, x - 1);
            tmp %= MOD;
            tmp *= (x + 2);
            tmp %= MOD;
        }
        else
        {
            tmp *= 1;
        }
        tmp *= mpow(2, i);
        tmp %= MOD;

        ans += tmp;
        ans %= MOD;
    }
    ans *= mpow(2, n);
    ans %= MOD;
    cout << ans << endl;

    return 0;
}