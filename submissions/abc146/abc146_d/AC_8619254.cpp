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

void dfs(map<pair<int, int>, int> &e, map<int, vector<int>> &g, vector<int> &edgeid, int cur, int ngnum)
{
    int t = 1;
    if (t == ngnum)
        t++;

    for (auto x : g[cur])
    {
        if (edgeid[e[{cur, x}]] != -1)
            continue;
        edgeid[e[{cur, x}]] = t;
        dfs(e, g, edgeid, x, t);
        t++;
        if (t == ngnum)
            t++;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    map<pair<int, int>, int> e;
    map<int, vector<int>> g;
    int ans = -1;
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        ans = max(ans, (int)g[a].size());
        g[b].push_back(a);
        ans = max(ans, (int)g[b].size());
        e[{a, b}] = i;
        e[{b, a}] = i;
    }
    vector<int> curnum(n, 1);
    vector<int> edgeid(n - 1, -1);
    dfs(e, g, edgeid, 0, -1);
    cout << ans << endl;
    rep(i, n - 1)
    {
        cout << edgeid[i] << endl;
    }

    return 0;
}
