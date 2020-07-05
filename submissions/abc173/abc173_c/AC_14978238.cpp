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
int h, w, k;

int calc(vector<string> &g, int y, int x)
{
    int ret = 0;
    rep(i, h)
    {
        if ((y >> i) & 1)
        {
            continue;
        }
        rep(j, w)
        {
            if ((x >> j) & 1)
            {
                continue;
            }
            if (g[i][j] == '#')
                ret++;
        }
    }
    return ret;
}
int main()
{

    cin >> h >> w >> k;
    vector<string> g(h);
    rep(i, h)
    {
        cin >> g[i];
    }
    int ans = 0;
    rep(i, 1 << h)
    {
        rep(j, 1 << w)
        {
            if (calc(g, i, j) == k)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
