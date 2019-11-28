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

int main()
{

    int h, w;
    cin >> h >> w;
    ll a[h][w], k, v;
    cin >> k >> v;
    rep(i, h) rep(j, w) cin >> a[i][j];
    ll imos[h + 1][w + 1];
    rep(j, w + 1) imos[0][j] = 0;
    rep(i, h)
    {
        imos[i + 1][0] = 0;
        rep(j, w)
        {
            imos[i + 1][j + 1] = imos[i + 1][j] + a[i][j];
        }
    }
    rep(j, w + 1)
    {
        rep(i, h)
        {
            imos[i + 1][j] += imos[i][j];
        }
    }

    rep(i, h + 1)
    {
        rep(j, w + 1)
        {
            cerr << imos[i][j] << " ";
        }
        cerr << endl;
    }
    int ans = 0;
    rep(sy, 1, h + 1) rep(sx, 1, w + 1) rep(ey, sy, h + 1) rep(ex, sx, w + 1)
    {
        int area = (ey - sy + 1) * (ex - sx + 1);
        ll cost = imos[ey][ex] - imos[ey][sx - 1] - imos[sy - 1][ex] + imos[sy - 1][sx - 1];
        cost += area * k;
        if (cost <= v)
        {
            //cerr << area << endl;
            ans = max(ans, area);
        }
    }

    cout << ans << endl;
    return 0;
}