#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

typedef pair<int, int> Pos;

int h, w;
bool is_valid(int y, int x)
{
    return 0 <= y && y < h && 0 <= x && x < w;
}

int main()
{
    cin >> h >> w;
    vector<string> g(h);
    int sy, sx, gy, gx;
    rep(i, h)
    {
        cin >> g[i];
    }
    rep(i, h) rep(j, w)
    {
        if (g[i][j] == 's')
        {
            sy = i;
            sx = j;
        }
        if (g[i][j] == 'g')
        {
            gy = i;
            gx = j;
        }
    }
    vector<vector<int>> cost(h, vector<int>(w, 3));
    deque<pair<Pos, int>> que;
    que.push_back({{sy, sx}, 0});
    int dy[4] = {0, 0, 1, -1};
    int dx[4] = {1, -1, 0, 0};
    while (!que.empty())
    {
        Pos cur = que.front().first;
        int curcost = que.front().second;
        que.pop_front();
        if (cost[cur.first][cur.second] <= curcost)
            continue;
        cost[cur.first][cur.second] = curcost;
        rep(i, 4)
        {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if (is_valid(ny, nx))
            {
                if (g[ny][nx] == '#')
                {
                    que.push_back({{ny, nx}, curcost + 1});
                }
                else
                {
                    que.push_back({{ny, nx}, curcost});
                }
            }
        }
    }
    if (cost[gy][gx] < 3)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}