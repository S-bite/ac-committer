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
map<int, int> ans;
map<int, vector<int>> g;

void dfs(int cur, int par, int nowval)
{
    ans[cur] = nowval % 6;
    for (auto x : g[cur])
    {
        if (x != par)
        {
            dfs(x, cur, nowval + 1);
        }
    }
}

vector<int> solve(int n, int start)
{
    ans.clear();
    deque<int> q[3];

    rep(i, 1, n + 1)
    {
        q[i % 3].push_back(i);
    }
    dfs(0, -1, start);
    vector<int> ansvec;
    rep(i, n)
    {
        int x = ans[i];
        if (x == 3)
            x = 0;
        if (x == 4)
            x = 2;
        if (x == 5)
            x = 1;
        if (q[x].empty())
        {
            return {};
        }
        else
        {
            ansvec.push_back(q[x].front());
            q[x].pop_front();
        }
    }
    return ansvec;
}

int main()
{
    ll n;
    cin >> n;
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    rep(i, 3)
    {
        auto ret = solve(n, i);
        if (ret.size() == 0)
            continue;
        for (auto x : ret)
        {
            cout << x << endl;
        }
        return 0;
    }
    cout << -1 << endl;
    return 0;
}