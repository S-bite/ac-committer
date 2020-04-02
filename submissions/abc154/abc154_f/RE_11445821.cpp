#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
const int MAX = 1010000;
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
    if (n % 2 == 0)
    {
        return (prev * prev) % MOD;
    }
    else
    {
        //assert(prev * prev * base > 0);
        return (((prev * prev) % MOD) * base) % MOD;
    }
}

int main()
{
    COMinit();
    ll a, c, b, d;
    cin >> a >> c >> b >> d;
    ll ans = 0;
    rep(i, a, b + 1)
    {
        ll tmp = (d + 1) * COM(d + i + 1, d + 1);
        tmp %= MOD;
        tmp -= (c * COM(c + i, c)) % MOD;
        while (tmp < 0)
            tmp += MOD;
        tmp *= mpow(i + 1, MOD - 2);
        tmp %= MOD;
        ans += tmp;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
