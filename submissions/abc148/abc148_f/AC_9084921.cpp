#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
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
vector<int> search2(map<int, vector<int>> &g, int u, int n)
{
    deque<pair<int, int>> que;
    que.clear();
    map<int, bool> used;
    used.clear();
    que.push_back({u, 0});
    vector<int> ret(n, -1);
    while (!que.empty())
    {
        int cur = que.front().first, cost = que.front().second;
        que.pop_front();
        if (used[cur] == true)
        {
            continue;
        }
        ret[cur] = cost;
        used[cur] = true;

        for (auto x : g[cur])
        {
            que.push_back({x, cost + 1});
        }
    }
    return ret;
}

int main()
{
    int n, u, v;
    cin >> n >> u >> v;
    u--;
    v--;
    map<int, vector<int>> g;
    g.clear();

    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        //cerr << "*" << a << b << endl;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    auto udist = search2(g, u, n);
    auto vdist = search2(g, v, n);
    int ans = -1;
    rep(i, n)
    {
        if (udist[i] > vdist[i])
        {
            continue;
        }
        int cur = vdist[i];
        if (g[i].size() == 1)
            cur -= 1;

           ans = max(ans, cur);
    }

    cout << ans << endl;
    return 0;
}