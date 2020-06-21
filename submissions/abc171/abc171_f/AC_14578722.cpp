#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
random_device rnd;
mt19937 mt(rnd());
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1000000007ll;

//from https://drken1215.hatenablog.com/entry/2018/06/08/210000
const int MAX = 2010000;

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
    if (n == k)
    {
        return 1;
    }
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll mpow(ll base, ll num)
{
    if (num == 0)
    {
        return 1;
    }
    ll prev = mpow(base, num / 2);

    if (num % 2 == 0)
    {
        return (prev * prev) % MOD;
    }
    else
    {

        return (((prev * prev) % MOD) * base) % MOD;
    }
}

int main()
{
    COMinit();
    int k;
    cin >> k;
    string s;
    cin >> s;
    int n = s.size();
    ll ans = 0;
    rep(i, n, n + k + 1)
    {
        //cerr << mpow(25, i - n) << endl;

        // ((COM(i, n) * mpow(25, i - n) % MOD) * mpow(26, n + k - i)) % MOD << endl;
        //  cerr << "*" << COM(i - 1, n - 1) << " " << mpow(25, i - n) << " " << mpow(26, n + k - i) << endl;
        ll tmp = (((COM(i - 1, n - 1) * mpow(25, i - n)) % MOD) * mpow(26, n + k - i)) % MOD;
        //cerr << tmp << endl;
        ans += tmp % MOD;
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}