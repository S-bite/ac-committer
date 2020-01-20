#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

const ll MOD = 1e9 + 7;

int main(int argc, char const *argv[])
{
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> w(n), v(n);
    rep(i, n)
    {
        cin >> w[i] >> v[i];
    }
    ll dp[n + 1][301];
    rep(i, n + 1)
    {
        rep(j, 301)
        {
            dp[i][j] = 0;
        }
    }
    dp[1][0] = v[0];
    rep(i, n)
    {

        rep(j, 1, i + 1)
        {
            rep(k, 301)
            {
                if (k - (w[i] - w[0]) >= 0)
                    dp[j][k] = max(dp[j][k], dp[j - 1][k - (w[i] - w[0])] + v[i]);
            }
        }
    }
    ll ans = -1;
    rep(i, n + 1)
    {

        rep(j, 301)
        {
            ll curw = w[0] * i + j;
            if (curw <= m)
            {
                cerr << i << " " << j << " " << dp[i][j] << endl;
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
