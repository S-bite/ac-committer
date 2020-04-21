#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
random_device rnd;
mt19937 mt(rnd());

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;
int main()
{
    int n;
    cin >> n;
    vector<pair<ll, ll>> p(n);
    rep(i, n)
    {
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(ALL(p), greater<PII>());
    VVL dp(n + 1, VL(n + 1, -1));
    dp[0][0] = 0;
    //dp[0][1] = abs(n - p[0].second) * p[0].first;
    //dp[1][0] = abs(p[0].second) * p[0].first;
    rep(i, n)
    {

        dp[i + 1][0] = dp[i][0] + llabs(p[i].second - i) * p[i].first;
        dp[0][i + 1] = dp[0][i] + llabs(n - 1 - i - p[i].second) * p[i].first;
    }
    cerr << dp[n][0] << endl;
    //    cerr << dp[0][n] << endl;
    rep(i, 1, n)
    {
        rep(j, 1, n)
        {
            if (i + j > n)
            {
                continue;
            }
            //assert(dp[i][j] != -1);

            //dp[i + 1][j] = max(dp[i][j] + abs(p[i + j].second - i) * p[i + j].first, dp[i + 1][j - 1] + abs(n - j - p[i + j].second) * p[i + j].first);
            //dp[i][j + 1] = max(dp[i][j] + abs(p[i + j].second - j) * p[i + j].first, dp[i - 1][j + 1] + abs(n - i - p[i + j].second) * p[i + j].first);
            dp[i][j] = max(dp[i - 1][j] + llabs(p[i + j - 1].second - (i - 1)) * p[i + j - 1].first, dp[i][j - 1] + llabs(n - 1 - (j - 1) - p[i + j - 1].second) * p[i + j - 1].first);
        }
    }
    ll ans = 0;
    rep(i, n + 1)
    {
        chmax(ans, dp[i][n - i]);
    }
    cout << ans << endl;
    return 0;
}