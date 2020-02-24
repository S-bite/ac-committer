#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;

struct Edge
{
    int to;
    int cap;
    int rev;
};

void add_edge(map<int, vector<Edge>> &g, int from, int to, int cap)
{
    g[from].push_back((Edge){to, cap, (int)g[to].size()});
    g[to].push_back((Edge){from, 0, (int)g[from].size() - 1});
}

int dfs(map<int, vector<Edge>> &g, map<int, bool> &visited, int cur, int dst, int f)
{
    if (cur == dst)
        return f;
    visited[cur] = true;
    for (auto &e : g[cur])
    {
        if (!visited[e.to] && e.cap > 0)
        {
            int tmp = dfs(g, visited, e.to, dst, min(f, e.cap));
            if (tmp > 0)
            {
                e.cap -= tmp;
                g[e.to][e.rev].cap += tmp;
                return tmp;
            }
        }
    }
    return 0;
}
int maxFlow(map<int, vector<Edge>> &g, int s, int t)
{
    map<int, bool> visited;
    int ret = 0, tmp = 0;
    do
    {
        visited.clear();
        tmp = dfs(g, visited, s, t, IINF);
        ret += tmp;
    } while (tmp != 0);
    return ret;
}

int main(int argc, char const *argv[])
{
    map<int, vector<Edge>> g;
    int h, w;
    cin >> h >> w;
    int start = h + w;
    int end = start + 1;
    rep(i, h)
    {
        string s;
        cin >> s;
        rep(j, w)
        {
            int x = h + j;
            int y = i;
            if (s[j] == 'S')
            {
                add_edge(g, start, x, IINF);
                add_edge(g, start, y, IINF);
            }
            else if (s[j] == 'T')
            {
                add_edge(g, x, end, IINF);
                add_edge(g, y, end, IINF);
            }
            else if (s[j] == 'o')
            {
                add_edge(g, y, x, 1);
                add_edge(g, x, y, 1);
            }
        }
    }
    int ans = maxFlow(g, start, end);
    if (ans == IINF)
        ans = -1;
    cout << ans << endl;
    return 0;
}
