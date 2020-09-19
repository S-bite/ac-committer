#include <bits/stdc++.h>
#include <atcoder/all>
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
const ll MOD = 998244353;
ll op(ll a, ll b)
{
    return (a + b) % MOD;
}

ll e()
{
    return ll(0);
}

int main()
{
    int n, k;
    cin >> n >> k;
    segtree<ll, op, e> seg(n + 10);
    vector<PII> v(k);
    rep(i, k)
    {
        cin >> v[i].first >> v[i].second;
    }
    seg.set(0, 1);
    rep(i, 1, n)
    {
        rep(j, k)
        {
            ll cur = seg.get(i);
            ll tmp = (cur + seg.prod((ll)max(0ll, (ll)i - v[j].second), (ll)max(0, i - v[j].first + 1)) % MOD) % MOD;
            seg.set(i, tmp);
        }
    }
    cout << seg.get(n - 1) << endl;
    return 0;
}