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

int main()
{
    int n;
    cin >> n;
    VVL d(n, VL(n, 0));
    ll ans = 0;
    rep(i, n) rep(j, n)
    {
        cin >> d[i][j];
    }
    auto war = d;
    rep(k, n) rep(i, n) rep(j, n)
    {
        chmin(war[i][j], war[i][k] + war[k][j]);
    }
    rep(i, n) rep(j, n)
    {
        if (war[i][j] < d[i][j])
        {
            cout << -1 << endl;
            return 0;
        }
    }
    rep(i, n) rep(j, n)
    {
        bool add = true;
        rep(k, n)
        {
            if (k != i && k != j && d[i][j] == d[i][k] + d[k][j])
            {
                add = false;
            }
        }
        if (add)
        {
            ans += d[i][j];
        }
    }
    cout << ans / 2 << endl;
    return 0;
}