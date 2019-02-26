#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll unsigned long long
#define lld long double
#ifdef DEBUG
#define line() cout << "[" << __LINE__ << "] ";
#define dump(i) cout << #i ": " << i << " ";
#define dumpl(i) cout << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
using namespace std;
ll cmb[51][51];

int main(int argc, char const *argv[])
{
    rep(i, 51)
    {
        cmb[i][0] = 1;
        rep(j, 1, i + 1)
        {
            cmb[i][j] = cmb[i - 1][j - 1] + cmb[i - 1][j];
        }
    }
    int n, a, b;
    cin >> n >> a >> b;
    ll v[n];
    rep(i, n) cin >> v[i];
    sort(v, v + n, greater<ll>());
    rep(i, n) dumpl(v[i]);

    ll target = 0;
    rep(i, a) target += v[i];
    cout << fixed << ((lld)target) / a << endl;
    if (v[0] != v[a - 1])
    {
        int x = 0, y = 0;
        rep(i, n)
        {
            if (v[i] == v[a])
                x++;
        }

        rep(i, a)
        {
            if (v[i] == v[a])
                y++;
        }
        cout << cmb[x][y] << endl;
    }
    else
    {
        ll ans = 0, x = 0;
        rep(i, n) if (v[i] == v[0]) x++;
        rep(i, a, b + 1)
        {
            ans += cmb[x][i];
        }
        cout << ans << endl;
    }
    return 0;
}
