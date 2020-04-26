#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
random_device rnd;
mt19937 mt(rnd());

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;

map<int, ll> D;
map<int, ll> C;

vector<ll> dijkstra(map<int, vector<pair<int, pair<ll, ll>>>> &g, int v, int start, ll startmoney) //{行き先,{通行時間,銀貨}}
{
    vector<ll> cost(v, INF);
    vector<ll> money(v, 0);

    int cur = start;
    priority_queue<pair<ll, pair<int, ll>>, vector<pair<ll, pair<int, ll>>>, greater<pair<ll, pair<int, ll>>>> pque; //{コスト, 今いるとこ, お金}
    rep(i, 250)
    {
        pque.push({0ll + D[start] * i, {start, startmoney + C[start] * i}});
    }
    while (!pque.empty())
    {

        cur = pque.top().second.first;
        ll curmoney = pque.top().second.second;
        assert(cur >= 0);
        ll curcost = pque.top().first;
        pque.pop();
        if ((curcost >= cost[cur] && curmoney <= money[cur]) || curmoney < 0)
        {
            continue;
        }
        chmin(cost[cur], curcost);
        chmax(money[cur], curmoney);

        for (auto x : g[cur])
        {
            int to = x.first;
            ll costtime = x.second.first;
            ll costmoney = x.second.second;
            ll curchangenum = 0;
            while (curmoney + C[cur] * curchangenum - costmoney <= 250 || curchangenum == 0)
            {
                pque.push({curcost + costtime + D[cur] * curchangenum, {to, curmoney - costmoney + C[cur] * curchangenum}});
                curchangenum++;
            }
        }
    }
    return cost;
}

int main()
{
    ll n, m, s;
    cin >> n >> m >> s;
    map<int, vector<pair<int, pair<ll, ll>>>> g;
    rep(i, m)
    {
        ll u, v, a, b;
        cin >> u >> v >> a >> b;
        u--;
        v--;
        g[u].push_back({v, {b, a}});
        g[v].push_back({u, {b, a}});
    }
    rep(i, n)
    {
        int t1, t2;
        cin >> t1 >> t2;
        C[i] = t1;
        D[i] = t2;
    }
    auto ans = dijkstra(g, n, 0, s);
    rep(i, 1, n)
    {
        cout << ans[i] << endl;
    }
    return 0;
}