#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
const int IINF = 1 << 29;
typedef vector<vector<int>> VVI;
typedef vector<int> VI;
typedef pair<int, int> PII;

VI dijkstra(map<int, vector<PII>> &g, int size, int start)
{
    VI dist(size, IINF);
    map<int, bool> visited;
    priority_queue<PII> pq;
    pq.push({0, start});
    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if (visited[cur])
        {
            continue;
        }
        visited[cur] = true;
        dist[cur] = cost;
        for (auto x : g[cur])
        {
            if (visited[x.second])
            {
                pq.push({cost + x.second, x.first});
            }
        }
    }
    return dist;
}

VVI warshallFloyd(map<int, vector<PII>> &g, int n)
{
    VVI dist(n, VI(n, IINF));
    rep(i, n) dist[i][i] = 0;
    rep(i, n)
    {
        for (auto x : g[i])
        {
            int j = x.first;
            int cost = x.second;
            dist[i][j] = cost;
        }
    }
    rep(k, 1, n)
    {
        rep(i, 1, n)
        {
            rep(j, 1, n)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return dist;
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    map<int, vector<PII>> g;
    rep(i, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    auto dist = warshallFloyd(g, n);
    int ans = IINF;
    for (auto x : g[0])
    {
        for (auto y : g[0])
        {
            if (x == y)
                continue;
            int i = x.first;
            int j = y.first;
            int cost1 = x.second;
            int cost2 = y.second;
            ans = min(ans, cost1 + dist[i][j] + cost2);
        }
    }
    if (ans == IINF)
        cout << -1 << endl;
    else
        cout << ans << endl;

    return 0;
}
