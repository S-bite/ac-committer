#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
const ll INF = 1ll << 60;
const int IINF = 1 << 30;
int n, m;
map<int, int> dist;
map<int, vector<pair<int, int>>> g;
map<int, bool> visited;

void update(int cur)
{
    if (visited[cur])
        return;
    visited[cur] = true;
    assert(dist[cur] != IINF);
    for (auto x : g[cur])
    {
        int to = x.first;
        int cost = x.second;
        int newdist = dist[cur] + cost;
        if (dist[to] != IINF && dist[to] != newdist)
        {
            cerr << cur << " " << to << endl;
            cout << "No" << endl;
            exit(0);
        }
        dist[to] = newdist;
        update(to);
    }
}

int main()
{
    cin >> n >> m;
    rep(i, n)
    {
        dist[i + 1] = IINF;
    }
    rep(i, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, -c});
    }
    rep(i, 1, n + 1)
    {
        if (dist[i] == IINF)
        {
            visited.clear();
            dist[i] = 0;
            update(i);
        }
    }
    cout << "Yes" << endl;
    return 0;
}