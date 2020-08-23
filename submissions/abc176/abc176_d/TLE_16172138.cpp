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
int h, w;

vector<ll> dijkstra(map<int, vector<pair<int, int>>> &g, int start)
{
    ll n = h * w;
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
        for (auto &&x : g[cur])
        {
            int next = x.first;
            ll d = x.second;
          	if (cost+d<ret[next])
            pque.push({cost + d, next});
        }
    }

    return ret;
}

bool is_valid(int y, int x)
{
    return 0 <= y && y < h && 0 <= x && x < w;
}

int main()
{
    cin >> h >> w;
    int sy, sx, gy, gx;
    cin >> sy >> sx >> gy >> gx;
    sy--;
    sx--;
    gy--;
    gx--;
    vector<string> g(h);
    rep(i, h)
    {
        cin >> g[i];
    }
    map<int, vector<pair<int, int>>> graph;
    rep(y, h)
    {
        rep(x, w)
        {
            int dx[5] = {-2, -1, 0, 1, 2};
            int dy[5] = {-2, -1, 0, 1, 2};
            rep(i, 5) rep(j, 5)
            {
                if (dy[i] == 0 && dx[j] == 0)
                    continue;
                int ny = y + dy[i];
                int nx = x + dx[j];

                if (is_valid(ny, nx) && g[ny][nx] == '.')
                {
                    if ((dy[i] == 1 && dx[j] == 0) || (dy[i] == -1 && dx[j] == 0) || (dy[i] == 0 && dx[j] == 1) || (dy[i] == 0 && dx[j] == -1))
                    {
                        graph[w * y + x].push_back({w * ny + nx, 0});
                    }
                    else
                    {
                        graph[w * y + x].push_back({w * ny + nx, 1});
                    }
                }
            }
        }
    }
    auto cost = dijkstra(graph, w * sy + sx);
    if (cost[w * gy + gx] == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << cost[w * gy + gx] << endl;
    }
    return 0;
}
