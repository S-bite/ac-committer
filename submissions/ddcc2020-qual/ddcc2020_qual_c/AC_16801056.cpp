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

    int h, w, k;
    cin >> h >> w >> k;
    vector<string> g(h);
    rep(i, h)
    {
        cin >> g[i];
    }
    VVI ans(h, VI(w, -1));
    int next = 1;
    rep(i, h)
    {

        int col = -1;
        rep(j, w)
        {
            if (g[i][j] == '#')
            {
                if (col == -1)
                {
                    rep(jj, j)
                    {
                        ans[i][jj] = next;
                    }
                }
                col = next;
                next++;
            }
            ans[i][j] = col;
        }
    }

    rep(loop, h)
    {
        rep(i, h) rep(j, w)
        {
            if (i != 0 && ans[i][j] == -1)
            {
                ans[i][j] = ans[i - 1][j];
            }
            if (i != h - 1 && ans[i][j] == -1)
            {
                ans[i][j] = ans[i + 1][j];
            }
        }
    }
    rep(i, h)
    {
        rep(j, w)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}