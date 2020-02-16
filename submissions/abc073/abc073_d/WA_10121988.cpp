#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
const ll INF = 1ll << 30;

vector<vector<ll>> warshall_floyd(int n, vector<vector<ll>> &g)
{
    auto ret = g;
    rep(k, n)
    {
        rep(i, n)
        {
            rep(j, n)
            {
                if (ret[i][k] + ret[k][j] < ret[i][j])
                {
                    ret[i][j] = ret[i][k] + ret[k][j];
                }
            }
        }
    }
    return ret;
}

int main()
{
    int n, m, r;
    cin >> n >> m >> r;
    vector<int> p(r);
    rep(i, r)
    {
        cin >> p[i];
        p[i]--;
    }
    vector<vector<ll>> g(n, vector<ll>(n, INF));
    rep(i, n) g[i][i] = 0;
    rep(i, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a][b] = c;
        g[b][a] = c;
    }
    ll ans = INF;
    auto cost = warshall_floyd(n, g);
    do
    {
        ll cur = 0;
        rep(i, r - 1)
        {
            cur += cost[p[i]][p[i + 1]];
        }
        ans = min(ans, cur);
    } while (next_permutation(ALL(p)));
    cout << ans << endl;
    return 0;
}