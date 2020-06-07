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
const int IINF = 1 << 28;
const ll INF = 1ll << 60;
const ll MOD = 1000000007;
int n;
vector<lld> dijkstra(map<int, vector<int>> &g, int start)
{
    priority_queue<pair<lld, int>, vector<pair<lld, int>>, greater<pair<lld, int>>> pque;
    pque.push({0, start});
    vector<lld> ret(n + 2, INF);
    while (!pque.empty())
    {
        auto cost = pque.top().first;
        auto cur = pque.top().second;
        pque.pop();
        if (ret[cur] <= cost)
            continue;
        ret[cur] = cost;
        for (auto x : g[cur])
        {
            int next = x;
            pque.push({cost + 1, next});
        }
    }

    return ret;
}
int main()
{
    int m;
    cin >> n >> m;
    map<int, vector<int>> g;
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int s;
    cin >> s;
    s--;
    int k;
    cin >> k;

    vector<int> v(k + 1);
    v[0] = s;
    rep(i, k)
    {
        cin >> v[i + 1];
        v[i + 1]--;
    }
    VVI dist(v.size(), VI(v.size()));
    rep(i, v.size())
    {
        auto ret = dijkstra(g, v[i]);
        rep(j, v.size())
        {
            dist[i][j] = ret[v[j]];
        }
    }

    int N = v.size();

    VVI dp(1 << N, VI(N, IINF));
    dp[1 << 0][0] = 0;
    rep(i, 1 << N)
    {
        rep(from, N)
        {
            if (dp[i][from] >= IINF)
                continue;
            rep(to, N)
            {
                if (i & 1 << to)
                    continue;
                int next = i | 1 << to;
                int d = dp[i][from] + dist[from][to];
                if (d < dp[next][to])
                {
                    dp[next][to] = d;
                }
            }
        }
    }
    int ans = IINF;
    rep(i, N)
    {
        chmin(ans, dp[(1 << N) - 1][i]);
    }
    cout << ans << endl;
    return 0;
}
