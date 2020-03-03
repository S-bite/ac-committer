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
void dfs(VVI &g, int cur)
{
    if (cur == 8)
    {
        rep(i, 8)
        {
            rep(j, 8)
            {
                cout << (g[i][j] == 1 ? "Q" : ".");
            }
            cout << endl;
        }
        exit(0);
    }
    rep(i, 8) rep(j, 8)
    {
        if (g[i][j] == 1)
            continue;
        g[i][j] = 1;
        if (check(g))
        {
            dfs(g, cur + 1);
        }
        g[i][j] = 0;
    }
}

int main(int argc, char const *argv[])
{
    VVI g(8, VI(8, 0));
    map<int, bool> mp;
    rep(i, 8)
    {
        string s;
        cin >> s;
        rep(j, 8)
        {
            g[i][j] = s[j] == 'Q' ? 1 : 0;
        }
    }
    dfs(g, 3);
    cout << "No Answer" << endl;
    return 0;
}
