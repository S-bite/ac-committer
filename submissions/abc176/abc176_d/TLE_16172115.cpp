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

vector<ll> dijkstra(vector<vector<pair<int, int>>> &g, int start)
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
    VVI cost(h, VI(w, IINF));
    deque<pair<PII, int>> que;
    que.push_back({{sy, sx}, 0});
    while (!que.empty())
    {
        while (!que.empty())
        {
            int cy = que.front().first.first;
            int cx = que.front().first.second;
            int cc = que.front().second;
            que.pop_front();
            if (cc >= cost[cy][cx])
                continue;
            cost[cy][cx] = cc;
            int dy[4] = {1, -1, 0, 0};
            int dx[4] = {0, 0, 1, -1};
            rep(i, 4)
            {

                int ny = cy + dy[i];
                int nx = cx + dx[i];
                if (is_valid(ny, nx) && g[ny][nx] == '.' && cost[ny][nx] > cc)
                {
                    que.push_back({{ny, nx}, cc});
                }
            }
        }
        int dy[5] = {-2, -1, 0, 1, 2};
        int dx[5] = {-2, -1, 0, 1, 2};
        //cerr << "aaa" << endl;
        rep(y, h)
        {
            rep(x, w)
            {
                if (cost[y][x] == IINF)
                    continue;
                rep(i, 5)
                {
                    rep(j, 5)
                    {
                        int ny = y + dy[i];
                        int nx = x + dx[j];
                        if (is_valid(ny, nx) && g[ny][nx] == '.' && cost[ny][nx] == IINF)
                        {
                            que.push_back({{ny, nx}, cost[y][x] + 1});
                            //cerr << cost[y][x] + 1 << endl;
                            // j = 5;
                            // i = 5;
                            // x = w;
                            // y = h;
                        }
                    }
                }
            }
        }
    }
    if (cost[gy][gx] == IINF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << cost[gy][gx] << endl;
    }
    return 0;
}
