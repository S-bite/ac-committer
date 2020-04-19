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

double PI = 6.28318530717958623200 / 2.0;

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;

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
        return (prev * prev * base) % MOD;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    ll curMax = 0;
    ll curMin = 0;

    rep(i, k)
    {
        curMax += n - i;
        curMin += i;
    }
    rep(i, k, n + 2)
    {
        ans += curMax - curMin + 1;
        //  cerr << curMax << " " << curMin << endl;
        curMax += n - i;
        curMin += i;
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}
