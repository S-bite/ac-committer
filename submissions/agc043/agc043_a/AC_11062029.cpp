#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
const int IINF = 1 << 30;

int main(int argc, char const *argv[])
{
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    rep(i, h) cin >> g[i];
    vector<vector<int>> dp(h, vector<int>(w, IINF));
    if (g[0][0] == '#')
        dp[0][0] = 1;
    else
        dp[0][0] = 0;
    rep(i, h) rep(j, w)
    {
        if (i + 1 < h)
        {
            if (g[i + 1][j] == '#')
            {
                int tmp = dp[i][j];
                if (g[i][j] == '.')
                    tmp++;
                dp[i + 1][j] = min(dp[i + 1][j], tmp);
            }
            else
            {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            }
        }
        if (j + 1 < w)
        {
            if (g[i][j + 1] == '#')
            {
                int tmp = dp[i][j];
                if (g[i][j] == '.')
                    tmp++;
                dp[i][j + 1] = min(dp[i][j + 1], tmp);
            }
            else
            {
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
            }
        }
    }
    cout << dp[h - 1][w - 1] << endl;
    return 0;
}
