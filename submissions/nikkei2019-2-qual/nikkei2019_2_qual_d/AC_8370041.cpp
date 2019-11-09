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
#define INF 1ll << 60
using namespace std;
typedef map<int, vector<int>> Graph;
typedef map<int, map<int, ll>> WGraph;
#define int ll
vector<int> dijkstra(int v, WGraph &g, int r)
{
    vector<int> cost(v, INF);
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

signed main()
{
    int n, m;
    cin >> n >> m;
    int l[m], r[m], c[m];
    rep(i, m)
    {
        cin >> l[i] >> r[i] >> c[i];
        l[i]--;
        r[i]--;
    }
    WGraph g;

    vector<int> p;
    map<int, bool> mp;
    rep(i, m)
    {
        if (g[l[i]][r[i]] == 0)
        {
            g[l[i]][r[i]] = INF;
            g[r[i]][l[i]] = INF;
        }
        g[l[i]][r[i]] = min(c[i], g[l[i]][r[i]]);
        g[r[i]][l[i]] = min(c[i], g[r[i]][l[i]]);
        if (mp[l[i]] == false)
        {
            p.push_back(l[i]);
            mp[l[i]] = true;
        }
        if (mp[r[i]] == false)
        {
            p.push_back(r[i]);
            mp[r[i]] = true;
        }
    }
    sort(ALL(p));
    rep(i, 1, m)
    {
        g[i][i - 1] = 0;
    }
    auto cost = dijkstra(n, g, 0);
    if (cost[n - 1] == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << cost[n - 1] << endl;
    }
    return 0;
}
