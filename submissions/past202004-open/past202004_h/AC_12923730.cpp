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

map<PII, int> dijkstra(map<PII, vector<pair<PII, int>>> &g, PII start)
{
    map<PII, int> ret;
    rep(i, n) rep(j, m) ret[{i, j}] = IINF;
    deque<pair<PII, int>> que;
    que.push_back({start, 0});
    while (!que.empty())
    {
        auto cur = que.front().first;
        auto cost = que.front().second;
        assert(cost >= 0);
        //  cerr << cost << endl;
        que.pop_front();
        if (ret[cur] <= cost)
            continue;
        ret[cur] = cost;
        for (auto x : g[cur])
        {

            que.push_back({x.first, cost + x.second});
        }
    }
    return ret;
}

int main()
{
    cin >> n >> m;
    map<PII, vector<pair<PII, int>>> g;
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
    rep(i, 10)
    {
        for (auto &&from : mp[i])
        {
            for (auto &&to : mp[i + 1])
            {
                g[from].push_back({to, abs(from.first - to.first) + abs(from.second - to.second)});
            }
        }
    }
    auto ret = dijkstra(g, start);
    int ans = ret[goal];
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