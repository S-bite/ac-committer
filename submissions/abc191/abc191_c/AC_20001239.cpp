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
    vector<string> g(h);

    rep(i, h)
    {
        cin >> g[i];
    }
    int ans = 0;
    rep(i, 1, h)
    {

        rep(j, w)
        {
            if (g[i - 1][j] != g[i][j])
            {
                cerr << i << " " << j << g[i][j] << " " << g[i - 1][j] << endl;
                ans += 2;
                while (j < w && g[i - 1][j] != g[i][j])
                {
                    j++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}