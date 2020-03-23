#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
vector<vector<int>> ans(1010, vector<int>(1010, -1));
vector<string> g;
int h, w;
void dfs(int y, int x, int cur)
{
    if (ans[y][x] != -1 && ans[y][x] < cur) //|| (g[y][x] == '#' && cur != 0))
    {
        return;
    }
    //visited[{y, x}] = true;
    if (ans[y][x] == -1)
    {
        ans[y][x] = cur;
    }
    else
    {
        ans[y][x] = min(ans[y][x], cur);
    }
    if (y - 1 >= 0)
    {
        dfs(y - 1, x, cur + 1);
    }
    if (x - 1 >= 0)
    {
        dfs(y, x - 1, cur + 1);
    }
    if (y + 1 < h)
    {
        dfs(y + 1, x, cur + 1);
    }
    if (x + 1 < w)
    {
        dfs(y, x + 1, cur + 1);
    }
}

int main()
{
    cin >> h >> w;
    g.resize(h);
    rep(i, h)
    {
        cin >> g[i];
    }
    rep(i, h) rep(j, w)
    {
        if (g[i][j] == '#')
        {
            dfs(i, j, 0);
        }
    }
    int mans = -1;
    rep(i, h)
    {
        rep(j, w)
        {
            mans = max(mans, ans[i][j]);
            cerr << ans[i][j] << " ";
        }
        cerr << endl;
    }
    cout << mans << endl;
    return 0;
}