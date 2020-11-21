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

int main()
{
    map<int, vector<pair<int, int>>> g, gg;
    int n, m, c;
    cin >> n >> m >> c;
    rep(i, n)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back({ y, z });
        g[y].push_back({ x, z });
    }
    map<int, bool> visited;
    deque<tuple<int, int, int>> que;
    que.push_back({ 1, -1, 0 });
    while (!que.empty()) {
        int cur = get<0>(que.front());
        int prev = get<1>(que.front());
        int label = get<2>(que.front());
        que.pop_front();
        if (visited[cur])
            continue;
        visited[cur] = true;
        gg[cur].push_back({ prev, label });
        for (auto&& next : g[cur]) {
            que.push_back({ next.first, cur, next.second });
        }
    }
    map<int, int> ans;
    visited.clear();
    que.push_back({ 1, -1, n });
    while (!que.empty()) {
        int cur = get<0>(que.front());
        int prev = get<1>(que.front());
        int label = get<2>(que.front());
        que.pop_front();
        if (visited[cur])
            continue;
        visited[cur] = true;
        if (label > 0) {
        } else {
            label = abs(label);
            label--;
            if (label == 0)
                label = n;
        }
        ans[cur] = label;
        for (auto&& next : g[cur]) {
            if (next.second == label) {
                que.push_back({ next.first, cur, -next.second });
            } else {
                que.push_back({ next.first, cur, next.second });
            }
        }
    }
    rep(i, 1, n + 1)
    {
        cout << ans[i] << endl;
    }
    return 0;
}