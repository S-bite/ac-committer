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
#define MOD 1000000007ll

using namespace std;
ll ans = 1;
int n, k;

void bfs(map<int, vector<int>> &g, map<int, bool> &visited, int now, int pcost)
{
    visited[now] = true;

    ans = (ans * (k - pcost)) % MOD;

    int nowcost = 1;
    if (now != 1)
        nowcost++;
    for (auto x : g[now])
    {
        if (visited[x] == true)
        {
            continue;
        }

        bfs(g, visited, x, nowcost);
        nowcost++;
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> k;

    map<int, vector<int>> g;
    map<int, bool> visited;
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bfs(g, visited, 1, 0);
    cout << ans << endl;

    return 0;
}
