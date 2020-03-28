#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    x--;
    y--;
    int len = y - x + 1;

    vector<vector<int>> dist(n, vector<int>(n, 0));
    rep(i, n) rep(j, n)
    {
        dist[i][j] = abs(i - j);
    }
    dist[y][x] = 1;
    dist[x][y] = 1;

    rep(i, n)
    {
        rep(j, n)
        {
            dist[i][j] = min({dist[i][j],
                              dist[i][x] + dist[x][j]});
        }
    }

    rep(i, n)
    {
        rep(j, n)
        {
            dist[i][j] = min({dist[i][j],
                              dist[i][y] + dist[y][j]});
        }
    }
    map<int, int> ans;
    rep(i, n) rep(j, i + 1, n)
    {
        ans[dist[i][j]]++;
    }
    rep(i, 1, n)
    {
        cout << ans[i] << endl;
    }
    return 0;
}