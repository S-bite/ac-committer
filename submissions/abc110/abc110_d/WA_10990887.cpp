#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
#define int ll
const double EPS = 1e-3;
const double PI = 3.1415926535897932384626433832795028841971;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
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
vector<ll> primes;
void primeinit()
{
    primes.push_back(2);
    ll cur = 3;
    while (cur * cur <= 1000'100'000)
    {
        bool is_prime = true;
        for (auto prime : primes)
        {
            if (cur % prime == 0)
            {
                is_prime = false;
                break;
            }
            if (prime * prime > cur)
                break;
        }
        if (is_prime)
            primes.push_back(cur);
        cur++;
    }
}
map<ll, int> factorization(int m)
{
    map<ll, int> ret;
    for (ll prime : primes)
    {
        if (m % prime == 0)
        {
            while (m % prime == 0)
            {
                ret[prime]++;
                m /= prime;
            }
            if (m == 1)
                break;
        }
    }
    return ret;
}
signed main(int argc, char const *argv[])
{
    COMinit();
    cerr << "ok" << endl;
    primeinit();
    cerr << "ok" << endl;
    int n, m;
    cin >> n >> m;
    auto fact = factorization(m);
    ll ans = 1;
    for (auto x : fact)
    {
        ll num = x.second;
        ans *= COM(num + n - 1, n - 1);
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}
