#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
#ifdef DEBUG
#define line() cerr << "[" << __LINE__ << "] ";
#define dump(i) cerr << #i ": " << i << " ";
#define dumpl(i) cerr << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
using namespace std;
typedef map<int, vector<int>> Graph;
typedef map<int, map<int, int>> WGraph;

vector<int> dijkstra(int v, WGraph &g, int r)
{
    vector<int> cost(v, 1 << 30);
    cost[r] = 0;
    priority_queue<pair<int, int>> pq;

    pq.push({0, r});

    while (!pq.empty())
    {
        //cerr << "-------------------------------" << endl;
        auto t = pq.top();
        pq.pop();
        //cerr << t.second << "," << t.first << endl;
        if (cost[t.second] < -t.first)
        {
            continue;
        }
        for (auto x : g[t.second])
        {
            if (cost[x.first] > cost[t.second] + g[t.second][x.first])
            {
                cost[x.first] = cost[t.second] + g[t.second][x.first];
                //cerr << "update cost[" << x.first << "] with " << cost[x.first] << endl;
                pq.push({-cost[x.first], x.first});
            }
        }
    }
    return cost;
}

int main(int argc, char const *argv[])
{
    int n, m, t;
    cin >> n >> m >> t;
    vector<int> a(n, 0);
    rep(i, n) cin >> a[i];
    WGraph g1, g2;
    rep(i, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g1[a][b] = c;
        g2[b][a] = c;
    }
    auto cost1 = dijkstra(n, g1, 0);
    auto cost2 = dijkstra(n, g2, 0);
    ll ans = -1;
    rep(i, n)
    {
        ans = max(ans, (ll)a[i] * (ll)(t - cost1[i] - cost2[i]));
    }
    cout << ans << endl;
    return 0;
}
