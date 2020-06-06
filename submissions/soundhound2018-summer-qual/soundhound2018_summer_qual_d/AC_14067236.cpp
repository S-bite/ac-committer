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

vector<ll> dijkstra(map<int, vector<pair<int, ll>>> &g, int start)
{
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pque;
    pque.push({0, start});
    vector<ll> ret(n + 2, INF);
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
            int next = x.first;
            ll d = x.second;
            pque.push({cost + d, next});
        }
    }

    return ret;
}

int main()
{
    int m, s, t;
    cin >> n >> m >> s >> t;
    map<int, vector<pair<int, ll>>> g1, g2;
    s--;
    t--;
    rep(i, m)
    {
        int a, b, c1, c2;
        cin >> a >> b >> c1 >> c2;
        a--;
        b--;
        g1[a].push_back({b, c1});
        g1[b].push_back({a, c1});
        g2[a].push_back({b, c2});
        g2[b].push_back({a, c2});
    }
    auto costs = dijkstra(g1, s);
    auto costt = dijkstra(g2, t);
    priority_queue<pair<ll, int>> ans;
    ll base = 1000000000000000ll;

    rep(i, n)
    {
        ans.push({base - costs[i] - costt[i], i});
    }
    rep(i, n)
    {
        while (ans.top().second < i)
        {
            ans.pop();
        }
        cout << ans.top().first << endl;
    }

    return 0;
}