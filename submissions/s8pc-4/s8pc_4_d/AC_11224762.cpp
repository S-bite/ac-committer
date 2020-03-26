#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

vector<lld> dp1(151010, 0);
vector<lld> dp2(151010, 0);

vector<int> childnum(151010, 0);
vector<int> parvec(151010, 0);
map<int, vector<int>> g;

void dfs1(int cur, int par)
{
    parvec[cur] = par;
    lld ret = 0;
    for (auto x : g[cur])
    {
        if (x != par)
        {
            dfs1(x, cur);
            ret += 1 + dp1[x];
            childnum[cur]++;
        }
    }
    if (childnum[cur] != 0)
    {
        dp1[cur] = ret / (lld)childnum[cur];
    }
    else
    {
        dp1[cur] = 0;
    }
}

void dfs2(int cur, int par)
{
    if (par == -1)
    {
        dp2[cur] = dp1[cur];
    }
    else
    {

        int pnum = g[par].size();
        lld parexp;
        if (pnum == 1)
        {
            parexp = (dp1[par] * (childnum[par]) - dp1[cur]) / ((childnum[par]));
        }
        else
        {
            parexp = 1 + (dp1[par] * (g[par].size()) - dp1[cur] - 1) / (pnum - 1);
        }
        //cerr << cur << " " << par << " " << parexp << " " << pnum << endl;
        dp1[cur] = (dp1[cur] * childnum[cur] + (parexp)) / (lld)(childnum[cur] + 1);
        //cerr << dp1[cur] << endl;
    }
    for (auto x : g[cur])
    {
        if (x != par)
            dfs2(x, cur);
    }
}

int main()
{
    int n;
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
    dfs1(0, -1);

    /* rep(i, n)
    {
        cerr << fixed << setprecision(18) << dp1[i] << endl;
    }
    cerr << endl;
    */
    dfs2(0, -1);

    rep(i, n)
    {
        cout << fixed << setprecision(18) << dp1[i] << endl;
    }
    return 0;
}