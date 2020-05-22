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
    int h, w;
    cin >> h >> w;
    VVI g(h, VI(w, 0));
    rep(i, h) rep(j, w)
    {
        cin >> g[i][j];
        if ((i + j) % 2 == 0)
        {
            g[i][j] *= -1;
        }
    }
    VVI s(h + 1, VI(w + 1, 0));
    rep(i, h)
    {
        rep(j, w)
        {
            s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j] + g[i][j];
        }
    }
    // rep(i, h + 1)
    // {
    //     rep(j, w + 1)
    //     {
    //         cerr << s[i][j] << " ";
    //     }
    //     cerr << endl;
    // }
    int ans = 0;
    rep(sy, 0, h + 1) rep(sx, 0, w + 1) rep(ey, 0, h + 1) rep(ex, 0, w + 1)
    {
        int cur = s[ey][ex] - s[sy][ex] - s[ey][sx] + s[sy][sx];
        if (cur == 0)
        {
            //         cerr << cur << " " << sy << " " << sx << " " << ey << " " << ex << endl;
            chmax(ans, (ey - sy) * (ex - sx));
        }
    }
    cout << ans << endl;

    return 0;
}