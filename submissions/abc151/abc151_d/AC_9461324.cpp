#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()

using namespace std;
typedef pair<int, pair<int, int>> State;

const int INF = 1 << 30;
vector<vector<int>> bfs(vector<vector<int>> &g, int h, int w, int sy, int sx)
{
    assert(g[sy][sx] == 0);
    vector<vector<int>> ret(h, vector<int>(w, INF));
    priority_queue<State, vector<State>, greater<State>> pque;

    map<pair<int, int>, bool> mp;
    mp.clear();
    pque.push({0, {sy, sx}});
    while (!pque.empty())
    {
        auto cur = pque.top();
        pque.pop();
        if (mp[cur.second] == true)
        {
            continue;
        }
        ret[cur.second.first][cur.second.second] = cur.first;
        mp[cur.second] = true;
        int y = cur.second.first;
        int x = cur.second.second;
        if (y + 1 < h && g[y + 1][x] == 0)
        {
            pque.push({cur.first + 1, {y + 1, x}});
        }
        if (y - 1 >= 0 && g[y - 1][x] == 0)
        {
            pque.push({cur.first + 1, {y - 1, x}});
        }
        if (x + 1 < w && g[y][x + 1] == 0)
        {
            pque.push({cur.first + 1, {y, x + 1}});
        }
        if (x - 1 >= 0 && g[y][x - 1] == 0)
        {
            pque.push({cur.first + 1, {y, x - 1}});
        }
    }
    return ret;
}

int check(vector<vector<int>> &g, int h, int w, int sy, int sx)
{
    auto cost = bfs(g, h, w, sy, sx);
    int mcost = -1;
    rep(i, h) rep(j, w)
    {
        if (cost[i][j] == INF)
            continue;
        if (mcost < cost[i][j])
        {
            sy = i;
            sx = j;
            mcost = cost[i][j];
        }
    }
    return mcost;
}

int main()
{
    int h, w;
    cin >> h >> w;

    vector<vector<int>> g(h, vector<int>(w, 0));
    int sy, sx;
    rep(i, h) rep(j, w)
    {
        char s;
        cin >> s;
        if (s == '.')
        {
            g[i][j] = 0;
            sy = i;
            sx = j;
        }
        else
        {
            g[i][j] = 1;
        }
    }

    int ans = -1;
    rep(i, h)
    {
        rep(j, w)
        {
            if (g[i][j] == 0)
            {
                ans = max(ans, check(g, h, w, i, j));
            }
        }
    }
    cout << ans << endl;
    return 0;
}