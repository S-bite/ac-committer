#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
int h, w, k;
const int IINF = 1 << 30;

bool is_valid(int y, int x)
{
    return 0 <= y && y < h && 0 <= x && x < w;
}

int main()
{
    cin >> h >> w >> k;
    vector<string> g(h);
    rep(i, h) cin >> g[i];
    int sy, sx;
    rep(i, h)
    {
        rep(j, w)
        {
            if (g[i][j] == 'S')
            {
                sy = i;
                sx = j;
            }
        }
    }
    vector<vector<int>> dist(h, vector<int>(w, IINF));
    deque<pair<pair<int, int>, int>> que;
    que.push_back({{sy, sx}, 0});
    int dy[4] = {1, -1, 0, 0};
    int dx[4] = {0, 0, 1, -1};

    while (!que.empty())
    {
        auto cur = que.front().first;
        auto cost = que.front().second;
        que.pop_front();
        if (dist[cur.first][cur.second] <= cost)
        {
            continue;
        }
        dist[cur.first][cur.second] = cost;
        rep(i, 4)
        {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if (is_valid(ny, nx) && g[ny][nx] == '.')
            {
                que.push_back({{ny, nx}, cost + 1});
            }
        }
    }

    int ans = IINF;
    rep(i, h) rep(j, w)
    {
        if (dist[i][j] <= k)
        {
            int mindist = min({i, j, h - 1 - i, w - 1 - j});
            //cerr << mindist << endl;
            ans = min(ans, 1 + (mindist + k - 1) / k);
            if (mindist == 0)
            {
                ans = 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}