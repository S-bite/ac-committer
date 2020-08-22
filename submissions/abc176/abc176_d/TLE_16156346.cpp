#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
const int IINF = 1 << 28;
const ll INF = 1ll << 60;
int h, w;

//(y,x)がh*wの升目内に収まっているかを返す
bool is_valid(int y, int x)
{
    return 0 <= y && y < h && 0 <= x && x < w;
}

int main()
{
    cin >> h >> w;
    int sy, sx, gy, gx;
    cin >> sy >> sx >> gy >> gx;
    sy--;
    sx--;
    gy--;
    gx--;
    vector<string> g(h);
    rep(i, h)
    {
        cin >> g[i];
    }
    VVI cost(h, VI(w, IINF));
    deque<pair<PII, int>> que;
    que.push_back({{sy, sx}, 0});
    int cur = 0;
    while (!que.empty())
    {
        deque<PII> visited;
        vector<vector<bool>> used(h, vector<bool>(w, false));
        while (!que.empty())
        {
            int cy = que.front().first.first;
            int cx = que.front().first.second;
            int cc = que.front().second;
            que.pop_front();
            if (cc >= cost[cy][cx])
                continue;
            visited.push_back({cy, cx});

            cost[cy][cx] = cc;
            int dy[4] = {1, -1, 0, 0};
            int dx[4] = {0, 0, 1, -1};
            rep(i, 4)
            {

                int ny = cy + dy[i];
                int nx = cx + dx[i];
                if (is_valid(ny, nx) && g[ny][nx] == '.' && cost[ny][nx] > cc && used[ny][nx] == false)
                {
                    que.push_back({{ny, nx}, cc});
                    used[ny][nx] = true;
                }
            }
        }
        int dy[5] = {-2, -1, 0, 1, 2};
        int dx[5] = {-2, -1, 0, 1, 2};
        cur++;
        // assert(cur < 1500);
        used = vector<vector<bool>>(h, vector<bool>(w, false));
        while (!visited.empty())
        {
            int y = visited.front().first;
            int x = visited.front().second;
            visited.pop_front();
            rep(i, 5)
            {
                rep(j, 5)
                {
                    int ny = y + dy[i];
                    int nx = x + dx[j];
                    if (is_valid(ny, nx) && (g[ny][nx] == '.') && (cost[ny][nx] == IINF) && (used[ny][nx] == false))
                    {
                        que.push_back({{ny, nx}, cur});
                        used[ny][nx] = true;
                    }
                }
            }
        }
    }
    if (cost[gy][gx] == IINF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << cost[gy][gx] << endl;
    }
    return 0;
}