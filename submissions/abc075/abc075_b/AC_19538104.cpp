#include <bits/stdc++.h>
#include <atcoder/all>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define contain(x, y) (x.find(y) != x.end())

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
int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    rep(i, h)
    {
        cin >> g[i];
    }

    rep(i, h)
    {
        rep(j, w)
        {
            if (g[i][j] == '#')
            {
                cout << "#";
            }
            else
            {
                int ans = 0;
                rep(di, -1, 1 + 1)
                {
                    rep(dj, -1, 1 + 1)
                    {
                        int ni = i + di;
                        int nj = j + dj;
                        if (ni >= 0 && ni < h && ni >= 0 && nj < w)
                        {
                            if (g[ni][nj] == '#')
                            {
                                ans++;
                            }
                        }
                    }
                }
                cout << ans;
            }
        }
        cout << endl;
    }
}