#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
#define INF (1ll << 62)
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
typedef map<ll, map<int, int>> WGraph;
typedef pair<int, int> Edge;
vector<ll> bellmanford(int v, WGraph &g, int r)
{
    vector<ll> cost(v, INF);
    cost[r] = 0;
    rep(_, 2*v)
    {
        rep(i, v)
        {
            for (auto x : g[i])
            {
                int j = x.first;
                ll c = x.second;
                if (cost[j] > cost[i] + c)
                {
                    cost[j] = cost[i] + c;
                }
            }
        }
    }
    rep(i, v)
    {
        for (auto x : g[i])
        {
            int j = x.first;
            ll c = x.second;
            if (cost[j] > cost[i] + c)
            {
                return vector<ll>(v, -INF);
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
    rep(i, m)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        c = -c;
        g[a][b] = c;
    }
    auto cost = bellmanford(n, g, 0);
    if (-cost[n - 1] == INF)
    {
        cout << "inf" << endl;
    }
    else
    {

        cout << -cost[n - 1] << endl;
    }
    return 0;
}
