#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
random_device rnd;
mt19937 mt(rnd());
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1000000007;

int main()
{
    int n;
    cin >> n;
    VVL dp(n + 1, VL(2, 0));
    dp[0][0] = 1;
    dp[0][1] = 1;
    rep(i, n)
    {
        string s;
        cin >> s;
        if (s == "AND")
        {
            dp[i + 1][0] = (1ll << (i + 1)) + dp[i][0];
            dp[i + 1][1] = dp[i][1];
        }
        else
        {
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = (1ll << (i + 1)) + dp[i][1];
        }
        cerr << dp[i + 1][0] << " " << dp[i + 1][1] << endl;
    }
    cout << dp[n][1] << endl;
    return 0;
}