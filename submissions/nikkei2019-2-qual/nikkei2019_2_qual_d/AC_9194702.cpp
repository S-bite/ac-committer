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
#define INF (1ll << 60)
typedef map<int, vector<int>> Graph;

typedef map<int, map<int, ll>> WGraph;
vector<ll> dijkstra(int v, WGraph &g, int r)
{
    vector<ll> cost(v, INF);
    cost[r] = 0;
    priority_queue<pair<ll, int>> pq;

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
    int n, m;
    cin >> n >> m;
    WGraph g;
    rep(i, 1, n)
    {
        g[i][i - 1] = 0;
    }
    map<pair<int, int>, bool> used;
    rep(i, m)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--;
        b--;
        if (used[{a, b}])
        {
            g[a][b] = min(g[a][b], c);
        }
        else
        {
            g[a][b] = c;
        }
        used[{a, b}] = true;
    }
    ll ans = dijkstra(n, g, 0)[n - 1];
    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}
