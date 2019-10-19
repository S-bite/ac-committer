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
    pair<ll, ll> dp[n][n];
    rep(i, n) rep(j, n)
    {
        if (i == j)
        {
            dp[i][j] = {0, l};
        }
        else
        {
            dp[i][j] = {INF, -1};
        }
    }
    rep(i, m)
    {
        if (c[i] <= l)
        {
            dp[a[i]][b[i]] = {0, l - c[i]};
            dp[b[i]][a[i]] = {0, l - c[i]};
        }
    }
    bool flag;
    do
    {
        flag = false;
        rep(k, n) rep(j, n) rep(i, n)
        {
            if (dp[i][k].first == INF || dp[k][j].first == INF)
                continue;
            if (dist[k][j] > l || dist[i][k] > l)
                continue;
            int pena = (dp[i][k].second >= dist[k][j]) ? 0 : 1;
            int newFill = dp[i][k].first + dp[k][j].first + pena;
            int newRem = (pena == 1) ? l - dist[k][j] : dp[i][k].second - dist[k][j];
            if (dp[i][j].first > newFill || (dp[i][j].first == newFill && dp[i][j].second < newRem))
            {
                if (dp[i][j].first > newFill)
                    flag = true;

                dp[i][j] = {newFill, newRem};
                cerr << newFill << " " << newRem << endl;
                //dp[j][i] = dp[i][j];
            }
        }
        rep(k, n) rep(i, n) rep(j, n)
        {
            if (dp[i][k].first == INF || dp[k][j].first == INF)
                continue;
            if (dist[k][j] > l)
                continue;
            int pena = (dp[i][k].second >= dist[k][j]) ? 0 : 1;
            int newFill = dp[i][k].first + dp[k][j].first + pena;
            int newRem = (pena == 1) ? l - dist[k][j] : dp[i][k].second - dist[k][j];
            if (dp[i][j].first > newFill || (dp[i][j].first == newFill && dp[i][j].second < newRem))
            {
                if (dp[i][j].first > newFill)
                    flag = true;

                dp[i][j] = {newFill, newRem};
                cerr << newFill << " " << newRem << endl;
                //dp[j][i] = dp[i][j];
            }
        }

    } while (flag);
    int q;
    cin >> q;
    rep(i, q)
    {
        int s, t;
        cin >> s >> t;
        s--;
        t--;
        if (dp[s][t].first == INF)
            cout << -1 << endl;
        else
            cout << dp[s][t].first << endl;
    }
    return 0;
}
