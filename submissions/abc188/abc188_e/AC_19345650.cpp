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
vector<ll> cost;
vector<ll> maxi;

int root(vector<vector<int>> &rg, vector<bool> &visited, int cur)
{
    for (auto &&next : rg[cur])
    {
        if (visited[next] == false)
        {
            return root(rg, visited, next);
        }
    }
    return cur;
}

ll dfs(vector<vector<int>> &g, int cur)
{

    if (maxi[cur] != -1)
    {
        return maxi[cur];
    }
    ll ret = cost[cur];
    for (auto next : g[cur])
    {
        chmax(ret, dfs(g, next));
    }
    maxi[cur] = ret;
    return ret;
}
int main()
{
    int n, m;
    cin >> n >> m;

    cost = vector<ll>(n);
    maxi = vector<ll>(n, -1);

    rep(i, n)
    {
        cin >> cost[i];
    }
    vector<vector<int>> g(n), rg(n);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        rg[b].push_back(a);
    }
    vector<bool> visited(n, false);
    ll ans = -(ll)IINF;
    rep(i, n)
    {

        for (auto next : g[i])
        {
            //cerr << dfs(g, next) - cost[i] << endl;
            chmax(ans, dfs(g, next) - cost[i]);
        }
    }
    cout << ans << endl;
    return 0;
}