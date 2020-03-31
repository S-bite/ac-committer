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

const int IINF = 1 << 28;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;
map<int, vector<pair<int, int>>> g;
vector<vector<int>> dist(400, vector<int>(400, IINF));
int main()
{
    int n, m;
    cin >> n >> m;
    rep(i, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        //g[a].push_back({b, c});
        //g[b].push_back({a, c});
        dist[a][b] = c;
        dist[b][a] = c;
    }
    rep(i, n) dist[i][i] = 0;
    rep(k, n) rep(i, n) rep(j, n)
    {
        chmin(dist[i][j], dist[i][k] + dist[k][j]);
    }
    ll ans = 0;
    int q;
    cin >> q;
    rep(t, q)
    {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        chmin(dist[x][y], z);
        chmin(dist[y][x], z);
        ans = 0;
        rep(i, n) rep(j, n)
        {
            chmin(dist[i][j], dist[i][x] + dist[x][j]);
        }
        rep(i, n) rep(j, n)
        {
            chmin(dist[i][j], dist[i][y] + dist[y][j]);
        }
        rep(i, n) rep(j, n)
        {
            ans += dist[i][j];
        }

        cout << ans / 2 << endl;
    }
    return 0;
}
