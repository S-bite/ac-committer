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

void solve(int n, int m, map<int, vector<int>> &g, map<pair<int, int>, int> &edge, vector<pair<ll, int>> &d, int start)
{
    int cur = start;
    int curid = 0;
    vector<ll> ans(m, 1e9);
    map<int, char> mp;
    map<int, bool> used;
    while (curid < n)
    {

        mp[cur] = (curid % 2 == 0) ? 'B' : 'W';

        int next = d[curid + 1].first;
        bool flag = false;
        for (auto x : g[cur])
        {
            if (used[x])
                continue;
            if (d[x].first == next)
            {
                used[x] = true;
                ans[edge[{cur, x}]] = d[curid + 1].first;
                flag = true;
                cur = x;

                break;
            }
        }
        if (flag == false)
        {

            return;
        }

        curid++;
    }
    mp[cur] = (curid % 2 == 0) ? 'B' : 'W';

    rep(i, n)
    {
        cout << mp[i];
    }
    cout << endl;
    rep(i, m)
    {
        cout << ans[i] << endl;
    }
    exit(0);
}

int main(int argc, char const *argv[])
{
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, int>> d(n);
    rep(i, n)
    {

        cin >> d[i].first;
        d[i].second = i;
    }
    sort(ALL(d));
    if (d[0].first != d[1].first)
    {
        cout << -1 << endl;
        return 0;
    }
    map<pair<int, int>, int> edge;
    map<int, vector<int>> g;
    rep(i, m)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
        edge[{u, v}] = i;
        edge[{v, u}] = i;
    }
    rep(i, n)
    {
        if (d[i].first == d[0].first)
        {
            solve(n, m, g, edge, d, i);
        }
    }
    cout << -1 << endl;

    return 0;
}
