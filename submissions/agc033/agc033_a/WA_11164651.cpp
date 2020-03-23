#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
map<pair<int, int>, bool> visited;
vector<string> g;
int h, w;
bool is_valid(int y, int x)
{
    return 0 <= y && y < h && 0 <= x && x < w && visited[{y, x}] == false;
}

int main()
{
    cin >> h >> w;
    g.resize(h);
    rep(i, h)
    {
        cin >> g[i];
    }
    deque<pair<int, int>> que;
    rep(i, h) rep(j, w)
    {
        if (g[i][j] == '#')
        {
            que.push_back({i, j});
        }
    }
    int ans = 0;
    int dy[4] = {1,
                 -1,
                 0,
                 0};
    int dx[4] = {0,
                 0,
                 1,
                 -1};
    while (!que.empty())
    {
        deque<pair<int, int>> next;
        while (!que.empty())
        {
            auto cur = que.front();
            que.pop_front();

            int y = cur.first;
            int x = cur.second;
            rep(i, 4) if (is_valid(y + dy[i], x + dx[i]))
            {
                next.push_back({y + dy[i], x + dx[i]});
                visited[{y + dy[i], x + dx[i]}] = true;
            }
        }
        ans++;
        que = next;
    }
    cout << ans << endl;
    return 0;
}