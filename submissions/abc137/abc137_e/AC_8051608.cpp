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
    int n, m, p;
    cin >> n >> m >> p;
    ll a[m], b[m], c[m];
    rep(i, m)
    {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        b[i]--;
        c[i] = p - c[i];
    }
    const ll INF = (1ll << 60);
    ll dist[n];
    rep(i, n) dist[i] = INF;
    dist[0] = 0;
    rep(i, n) rep(j, m)
    {
        if (dist[a[j]] == INF)
            continue;
        if (dist[b[j]] > dist[a[j]] + c[j])
        {
            dist[b[j]] = dist[a[j]] + c[j];
            if (i == n - 1)
            {
                dist[b[j]] = -INF;
            }
        }
    }
    rep(i, n) rep(j, m)
    {
        if (dist[a[j]] == -INF)
        {
            dist[b[j]] = -INF;
        }
    }
    if (dist[n - 1] != -INF)
    {
        cout << max(0ll, -dist[n - 1]) << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
