#include <bits/stdc++.h>
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
random_device rnd;
mt19937 mt(rnd());

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;
int n, m;
int ans = IINF;
map<int, vector<PII>> mp;

void dfs(int cur, PII pos, int cost)
{
    if (cur == 10)
    {
        chmin(ans, cost);
        return;
    }
    for (auto &&p : mp[cur + 1])
    {
        dfs(cur + 1, p, cost + abs(p.first - pos.first) + abs(p.second - pos.second));
    }
}

int main()
{
    cin >> n >> m;
    map<PII, vector<PII>> g;
    vector<string> tmp(n);
    rep(i, n) cin >> tmp[i];
    PII start, goal;
    rep(i, n) rep(j, m)
    {
        if (tmp[i][j] == 'S')
        {
            start = {i, j};
            mp[0].push_back({i, j});
        }
        else if (tmp[i][j] == 'G')
        {
            goal = {i, j};
            mp[10].push_back({i, j});
        }
        else
        {
            mp[tmp[i][j] - '0'].push_back({i, j});
        }
    }
    dfs(0, start, 0);
    if (ans == IINF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}