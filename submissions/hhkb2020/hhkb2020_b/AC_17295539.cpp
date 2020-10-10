
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
    cerr << h << " " << w << endl;
    rep(i, h) cin >> g[i];
    int ans = 0;
    rep(i, h) rep(j, w)
    {
        if (g[i][j] == '#')
            continue;
        cerr << "@" << i << " " << j << endl;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        rep(k, 4)
        {
            int ny = i + dy[k];
            int nx = j + dx[k];
            if (0 <= ny && ny < h && 0 <= nx && nx < w)
            {
                if (g[ny][nx] == '.')
                {
                    cerr << ny << " " << nx << endl;
                    ans++;
                }
            }
        }
    }
    cout << ans / 2 << endl;
    return 0;
}