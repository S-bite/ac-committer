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

const ll MOD = (ll)(1e9 + 7ll);
const ll INF = (1ll << 60);

ll dijkstra(map<int, vector<pair<int, ll>>> &g, ll scost, int v, int start, int end)
{
    vector<ll> cost(v, INF);
    int cur = start;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pque;
    pque.push({scost, start});
    while (!pque.empty())
    {

        cur = pque.top().second;
        assert(cur >= 0);
        ll curcost = pque.top().first;
        pque.pop();
        if (cost[cur] < curcost)
        {
            continue;
        }
        cost[cur] = min(cost[cur], curcost);
        //cerr << cur << endl;

        for (auto x : g[cur])
        {
            // cerr << cur << "->" << x.first << endl;
            pque.push({labs(x.second + cost[cur]), x.first});
            pque.push({labs(x.second - cost[cur]), x.first});
        }
    }
    return cost[end];
}

int main(int argc, char const *argv[])
{
    int h, w;
    cin >> h >> w;
    int a[h][w], b[h][w];
    map<int, vector<pair<int, ll>>> g;
    rep(i, h) rep(j, w) cin >> a[i][j];
    rep(i, h) rep(j, w) cin >> b[i][j];
    rep(i, h) rep(j, w)
    {
        int cind = i * w + j;
        if (j + 1 < w)
        {
            g[cind].push_back({cind + 1, a[i][j + 1] - b[i][j + 1]});
            g[cind].push_back({cind + 1, b[i][j + 1] - a[i][j + 1]});
        }
        if (i + 1 < h)
        {
            g[cind].push_back({cind + w, a[i + 1][j] - b[i + 1][j]});
            g[cind].push_back({cind + w, b[i + 1][j] - a[i + 1][j]});
        }
    }
    cout << dijkstra(g, abs(b[0][0] - a[0][0]), h * w, 0, h * w - 1) << endl;

    return 0;
}
