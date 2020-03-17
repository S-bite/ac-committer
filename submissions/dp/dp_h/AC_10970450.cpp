#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;
VVL dp(1010, VL(1010, 0));

int main(int argc, char const *argv[])
{
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    rep(i, h) cin >> g[i];
    dp[0][0] = 1;
    rep(i, h) rep(j, w)
    {
        if (g[i][j] == '#')
            continue;
        if (j - 1 >= 0)
        {
            dp[i][j] += dp[i][j - 1];
        }
        if (i - 1 >= 0)
        {
            dp[i][j] += dp[i - 1][j];
        }
        dp[i][j] %= MOD;
    }

    cout << dp[h - 1][w - 1] << endl;

    return 0;
}
