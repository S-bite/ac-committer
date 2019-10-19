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

int main(int argc, char const *argv[])
{
    const ll INF = (1ll << 60);
    int n, m;
    ll l;
    cin >> n >> m >> l;
    int a[m], b[m];
    ll c[m];
    ll dist[n][n];
    rep(i, n) rep(j, n)
    {
        if (i == j)
            dist[i][j] = 0;
        else
            dist[i][j] = INF;
    }

    rep(i, m)
    {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        b[i]--;
        dist[a[i]][b[i]] = c[i];
        dist[b[i]][a[i]] = c[i];
    }

    rep(k, n) rep(i, n) rep(j, n)
    {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
    ll dp[n][n];
    rep(i, n) rep(j, n)
    {

        if (i == j)
            dp[i][j] = 0;
        else
            dp[i][j] = INF;
    }
    rep(i, n) rep(j, n)
    {
        if (dist[i][j] <= l)
            dp[i][j] = min(dp[i][j], 1ll);
    }
    rep(k, n) rep(i, n) rep(j, n)
    {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    }

    int q;
    cin >> q;
    rep(i, q)
    {
        int s, t;
        cin >> s >> t;
        s--;
        t--;
        if (dp[s][t] == INF)
            cout << -1 << endl;
        else
            cout << dp[s][t] - 1 << endl;
    }
    return 0;
}
