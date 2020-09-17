#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
random_device rnd;
mt19937 mt(rnd());
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1000000007;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool ok(vector<string> &g)
{
    VVI ans(10, VI(10, -1));
    int col = 0;
    rep(i, 10) rep(j, 10)
    {
        if (g[i][j] == 'o' && ans[i][j] == -1)
        {
            deque<pair<int, int>> que;
            que.push_back({i, j});
            while (!que.empty())
            {
                auto cur = que.front();
                que.pop_front();
                if (ans[cur.first][cur.second] == col)
                    continue;
                ans[cur.first][cur.second] = col;
                rep(k, 4)
                {
                    int ny = cur.first + dy[k];
                    int nx = cur.second + dx[k];
                    if (0 <= ny && ny < 10 && 0 <= nx && nx < 10 && g[ny][nx] == 'o')
                    {
                        que.push_back({ny, nx});
                    }
                }
            }
            col++;
        }
    }
    return col <= 1;
}

int main()
{
    vector<string> g(10);
    rep(i, 10)
    {
        cin >> g[i];
    }
    rep(i, 10) rep(j, 10)
    {
        if (g[i][j] == 'o')
            continue;
        g[i][j] = 'o';
        if (ok(g))
        {
            rep(y, 10)
            {
                rep(x, 10) cerr << g[y][x];
                cerr << endl;
            }
            cout
                << "YES" << endl;
            return 0;
        }
        g[i][j] = 'x';
    }
    cout << "NO" << endl;

    return 0;
}