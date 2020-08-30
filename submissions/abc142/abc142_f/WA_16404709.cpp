#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

const double EPS = 1e-3;
const double PI = 3.1415926535897932384626433832795028841971;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;

bool check(vector<vector<int>> &g, vector<bool> &visited)
{
    rep(i, visited.size())
    {

        if (visited[i])
        {
            int num = 0;
            for (auto &&next : g[i])
            {
                if (visited[next])
                {
                    num++;
                }
            }
            if (num != 1)
                return false;
        }
    }
    return true;
}

int depth = 0;
void dfs(vector<vector<int>> &g, int cur, vector<bool> &visited)
{
    depth++;
    if (depth > 1000)
    {
        depth--;
        return;
    }
    if (visited[cur] && check(g, visited))
    {

        vector<int> ans;
        rep(i, visited.size())
        {
            if (visited[i])
            {
                ans.push_back(i);
            }
        }
        cout << ans.size() << endl;
        rep(i, ans.size())
        {
            cout << ans[i] + 1 << endl;
        }
        exit(0);
    }
    visited[cur] = true;
    for (auto &&next : g[cur])
    {
        dfs(g, next, visited);
        visited[next] = false;
    }
    depth--;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
    }

    rep(i, n)
    {
        vector<bool> visited(n, false);
        dfs(g, i, visited);
        cerr << "done " << i << endl;
    }
    cout << -1 << endl;
    return 0;
}