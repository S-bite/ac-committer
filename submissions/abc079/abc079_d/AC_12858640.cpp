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
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1000000007;
int n = 10;
VI dijkstra(VVI &dist, int start)
{
    VI ret(n, IINF);
    deque<PII> que;
    que.push_back({0, start});
    while (!que.empty())
    {
        int cost = que.front().first;
        int cur = que.front().second;
        que.pop_front();
        if (cost < ret[cur])
        {
            ret[cur] = cost;
            rep(i, 10)
            {
                que.push_back({cost + dist[i][cur], i});
            }
        }
    }
    return ret;
}

int main()
{
    int h, w;
    cin >> h >> w;
    VVI dist(10, VI(10));
    rep(i, 10) rep(j, 10) cin >> dist[i][j];
    auto cost = dijkstra(dist, 1);
    ll ans = 0;
    rep(i, h) rep(j, w)
    {
        int t;
        cin >> t;
        if (t != -1)
            ans += cost[t];
    }
    cout << ans << endl;
    return 0;
}