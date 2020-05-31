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
const ll MOD = 1000000007;
int n;
int calc(VL &x, VL &y, ll dx, ll dy)
{
    map<pair<int, int>, int> mp;

    rep(i, n)
    {
        mp[{x[i], y[i]}] = i;
    }
    VI next(100, -1);
    VI par(100, -1);
    rep(i, n)
    {
        if (mp.count({x[i] + dx, y[i] + dy}) != 0)
        {
            int q = mp[{x[i] + dx, y[i] + dy}];
            next[i] = q;
            par[q] = i;
        }
    }
    int ret = 0;
    map<int, bool> used;
    rep(i, n)
    {
        int cur = i;
        while (par[cur] != -1)
        {
            cur = par[cur];
        }
        assert(cur != -1);
        if (used[cur])
            continue;
        used[cur] = true;
        ret++;
    }
    return ret;
}

int main()
{
    cin >> n;
    VL x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    int ans = IINF;
    rep(i, n) rep(j, n)
    {
        if (i == j)
            continue;
        ll dx = x[i] - x[j];
        ll dy = y[i] - y[j];
        chmin(ans, calc(x, y, dx, dy));
    }

    cout << ans << endl;
    return 0;
}
