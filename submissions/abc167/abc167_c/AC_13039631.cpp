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

ll n, m, x;
ll check(VVL &book, VL &cost, int order)
{
    VL skill(m, 0);
    ll ret = 0;
    rep(i, n)
    {
        if (((order >> i) & 1) == 1)
        {
            ret += cost[i];
            rep(j, m)
            {
                skill[j] += book[i][j];
            }
        }
    }
    rep(i, m)
    {
        if (skill[i] < x)
        {
            return -1;
        }
    }
    return ret;
}

int main()
{
    cin >> n >> m >> x;
    VVL book(n, VL(m, 0));
    VL cost(n);
    rep(i, n)
    {
        cin >> cost[i];
        rep(j, m) cin >> book[i][j];
    }
    ll ans = INF;
    rep(i, (1 << n))
    {
        auto ret = check(book, cost, i);
        if (ret != -1)
            chmin(ans, ret);
    }
    if (ans == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}