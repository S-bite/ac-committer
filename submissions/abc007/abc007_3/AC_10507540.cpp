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
using P = pair<int, int>;

const int IINF = 1 << 29;
const ll INF = 1ll << 60;

bool is_valid(int y, int x)
{
    return 0 <= y && y < 8 && 0 <= x && x < 8;
}

bool check(VVI &g)
{
    int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
    int dx[8] = {0, 0, 1, -1, 1, -1, -1, 1};
    rep(i, 8) rep(j, 8)
    {
        if (g[i][j] == 1)
        {
            rep(k, 8)
            {
                int ny = i;
                int nx = j;
                ny += dy[k];
                nx += dx[k];

                while (is_valid(ny, nx))
                {
                    if (g[ny][nx] == 1)
                    {
                        return false;
                    }
                    ny += dy[k];
                    nx += dx[k];
                }
            }
        }
    }
    return true;
}
void dfs(VVI &g, VVI &cost, int y, int x, int cur)

{
    int dy[4] = {1, -1, 0, 0};
    int dx[4] = {0, 0, 1, -1};
    cost[y][x] = min(cost[y][x], cur);
    rep(i, 4)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (g[ny][nx] == 0 && cost[ny][nx] > cur + 1)
        {
            dfs(g, cost, ny, nx, cur + 1);
        }
    }
}

int main(int argc, char const *argv[])
{
    int r, c;
    cin >> r >> c;
    int sy, sx, gy, gx;
    cin >> sy >> sx >> gy >> gx;
    sy--;
    sx--;
    gy--;
    gx--;
    VVI g(r, VI(c, 0)), cost(r, VI(c, IINF));
    map<int, bool> mp;
    rep(i, r)
    {
        string s;
        cin >> s;
        rep(j, c)
        {
            g[i][j] = s[j] == '#' ? 1 : 0;
        }
    }
    dfs(g, cost, sy, sx, 0);
    cout << cost[gy][gx] << endl;
    return 0;
}
