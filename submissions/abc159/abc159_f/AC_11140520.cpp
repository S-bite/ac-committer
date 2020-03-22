#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using PII = pair<int, int>;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 998244353;
VI v;
int n, s;
int main()
{
    cin >> n >> s;
    v.resize(n);
    rep(i, n)
    {
        cin >> v[i];
    }
    VVI dp(n + 1, VI(s + 1, 0));
    dp[0][0] = 1;
    rep(i, 1, n + 1)
    {
        rep(j, s + 1)
        {
            dp[i][j] += dp[i - 1][j];
            if (j - v[i - 1] == 0)
            {
                dp[i][v[i - 1]] += i;
            }
            else if (j - v[i - 1] >= 1)
            {
                dp[i][j] += dp[i - 1][j - v[i - 1]];
                dp[i][j] %= MOD;
            }
        }
    }
    ll ans = 0;

    rep(i, 1, n + 1)
    {
        cerr << dp[i][s] << endl;
        ans += dp[i][s];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}