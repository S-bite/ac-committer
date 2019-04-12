#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#ifdef DEBUG
#define line() cout << "[" << __LINE__ << "] ";
#define dump(i) cout << #i ": " << i << " ";
#define dumpl(i) cout << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
using namespace std;

int h, w, k;
bool makeUnit(vector<vector<int>> &g, vector<vector<bool>> &used, vector<pair<int, int>> &ret, int y, int x, int now)
{
    ret[now] = {y, x};
    used[y][x] = true;
    now++;
    if (now == k)
        return true;

    int r = min(w - 1, x + 1);
    int l = max(0, x - 1);
    int u = min(h - 1, y + 1);
    int d = max(0, y - 1);
    //   cerr << u << "," << d << "," << r << "," << l << "," << y << "," << x << endl;
    //    cerr << "checkstart" << endl;
    if (used[u][x] && used[d][x] && used[y][r] && used[y][l])
    {
        rep(i, now + 1)
        {
            //   cerr << ret[i].first << "," << ret[i].second << endl;
            //used[ret[i].first][ret[i].second] = false;
        }
        return false;
    }
    //  cerr << "checkend" << endl;
    // cerr << "pstart" << endl;
    pair<int, pair<int, int>> p[4];
    p[0] = {g[u][x], {u, x}};
    p[1] = {g[d][x], {d, x}};
    p[2] = {g[y][r], {y, r}};
    p[3] = {g[y][l], {y, l}};
    // cerr << "pend" << endl;

    sort(p, p + 4);

    int cy, cx;
    for (int i = 3; i >= 0; i--)
    {
        cy = p[i].second.first;
        cx = p[i].second.second;
        if (used[cy][cx] == false)
            break;
    }
    return makeUnit(g, used, ret, cy, cx, now);
}

int main()
{

    cin >> h >> w >> k;
    vector<vector<int>> g(h, vector<int>(w, 0));
    vector<vector<bool>> used(h, vector<bool>(w, false));

    rep(i, h)
    {
        string s;
        cin >> s;
        rep(j, w)
        {
            g[i][j] = s[j] - '0';
        }
    }
    vector<vector<pair<int, int>>> ans;
    int miss = 0;
    //cerr << "search" << endl;
    while (true)
    {
        int sy = rand() % h, sx = rand() % w;
        vector<pair<int, int>> ret(k, {-1, -1});
        //   cerr << "makestart" << endl;
        if (used[sy][sx] == true)
        {
            continue;
        }
        if (makeUnit(g, used, ret, sy, sx, 0))
        {
            ans.push_back(ret);
            miss = 0;
        }
        else
        {
            miss++;
        }

        //  cerr << "makeend" << endl;

        if (miss == 100)
            break;
    }
    cout << ans.size() << endl;
    rep(i, ans.size())
    {
        rep(j, k)
        {
            cout << ans[i][j].first + 1 << " " << ans[i][j].second + 1 << endl;
        }
    }
    return 0;
}