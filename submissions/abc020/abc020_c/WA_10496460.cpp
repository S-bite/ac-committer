#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PI = pair<int, int>;

const int IINF = 1 << 29;
const ll INF = 1ll << 60;
bool is_valid(int y, int x, VVI &g)
{
    return 0 <= x && x < g[0].size() && 0 <= y && y < g.size();
}

bool is_ok(VVI &g, int sy, int sx, int gy, int gx, int x, int t)
{
    deque<pair<PI, ll>> que;
    VVL dist(g.size(), VL(g[0].size(), INF));
    que.push_back({{sy, sx}, 0});
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    while (!que.empty())
    {
        PI cur = que.front().first;
        ll cost = que.front().second;
        que.pop_front();
        if (dist[cur.first][cur.second] < cost)
            continue;
        dist[cur.first][cur.second] = cost;
        rep(i, 4)
        {
            int ny = cur.first - dy[i];
            int nx = cur.second - dx[i];
            if (is_valid(ny, nx, g))
            {
                que.push_back({{ny, nx}, cost + (g[ny][nx] == 0 ? 1 : x)});
            }
        }
    }
    return dist[gy][gx] <= t;
}

int main(int argc, char const *argv[])
{
    int h, w, t;
    cin >> h >> w >> t;
    VVI g(h, VI(w, -1));
    int sy, sx, gy, gx;
    rep(i, h)
    {
        string s;
        cin >> s;
        rep(j, w)
        {
            if (s[j] == '#')
                g[i][j] = 1;
            else
                g[i][j] = 0;
            if (s[j] == 'S')
            {
                sy = i;
                sx = j;
            }
            else if (s[j] == 'G')
            {
                gy = i;
                gx = j;
            }
        }
    }
    int l = 1, r = 1 << 29;
    while (l + 1 != r)
    {
        int mid = (l + r) / 2;
        if (is_ok(g, sy, sx, gy, gx, mid, t))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout << l << endl;
    return 0;
}
