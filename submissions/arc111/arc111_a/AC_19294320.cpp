#include <bits/stdc++.h>
#include <atcoder/maxflow>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using namespace atcoder;
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
const ll MOD = 1000000007;
ll mpow(ll base, ll num, ll mod)
{
    if (num == 0)
    {
        return 1;
    }
    ll prev = mpow(base, num / 2, mod);
    if (num % 2 == 1)
    {
        return (prev * prev * base) % mod;
    }
    else
    {
        return (prev * prev) % mod;
    }
}
int main()
{
    ll n, m;
    cin >> n >> m;
    cout << (mpow(10, n, m * m) / m) % m << endl;
    return 0;
}