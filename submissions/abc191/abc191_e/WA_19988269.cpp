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

typedef map<int, vector<int>> Graph;
typedef map<int, map<int, int>> WGraph;

vector<int> dijkstra(int v, WGraph &g, int r)
{
    vector<int> cost(v, IINF);
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
int main()
{
    int n, m;
    cin >> n >> m;
    WGraph g;
    vector<int> self(n, -1);
    map<pair<int, int>, bool> used;
    rep(i, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        if (used[{a, b}] == false)
        {
            g[a][b] = c;
        }
        else
        {
            chmin(g[a][b], c);
        }
        used[{a, b}] = true;

        if (a == b)
        {
            self[a] = c;
        }
    }
    vector<vector<int>> cost(n);
    rep(i, n)
    {
        cost[i] = dijkstra(n, g, i);
    }
    rep(i, n)
    {
        int ans = IINF;
        rep(j, n)
        {
            if (i == j)
            {
                if (self[i] != -1)
                {
                    chmin(ans, self[i]);
                }
            }
            else if (cost[i][j] + cost[j][i] < ans)
            {
                ans = cost[i][j] + cost[j][i];
            }
        }
        if (ans == IINF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }

    return 0;
}