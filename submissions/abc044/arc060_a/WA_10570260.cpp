#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
#define chmin(x, y) x = min(x, y);
using namespace std;

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;

int main(int argc, char const *argv[])
{
    int n, a;
    cin >> n >> a;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    vector<vector<int>> dp(n + 1, vector<int>(2525, 0));
    dp[0][0] = 1;
    rep(i, n)
    {
        auto next = dp;
        rep(j, 1, n + 1)
        {
            rep(k, 2525)
            {
                if (k - v[i] >= 0)
                {
                    next[j][k] += dp[j - 1][k - v[i]];
                }
            }
        }
        dp = next;
    }
    ll ans = 0;
    rep(i, 1, n + 1)
    {
        if (a * i >= 2525)
            break;
        ans += dp[i][a * i];
    }
    cout << ans << endl;
    return 0;
}
