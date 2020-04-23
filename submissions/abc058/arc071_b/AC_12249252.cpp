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
random_device rnd;
mt19937 mt(rnd());

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;
int main()
{

    int n, m;
    cin >> n >> m;
    VL x(n), y(m);
    rep(i, n) cin >> x[i];
    rep(i, m) cin >> y[i];
    sort(ALL(x));
    sort(ALL(y));
    ll sx = 0;
    rep(i, n)
    {
        sx += MOD * n + i * x[i];
        sx %= MOD;
        sx -= (MOD * n + (n - 1 - i) * x[i]) % MOD;
        while (sx < 0)
            sx += MOD;
    }
    ll sy = 0;
    rep(i, m)
    {
        sy += MOD * m + i * y[i];
        sy %= MOD;
        sy -= (MOD * m + (m - 1 - i) * y[i]) % MOD;
        while (sy < 0)
            sy += MOD;
    }
    cout << (sx * sy) % MOD << endl;
    ;
    return 0;
}