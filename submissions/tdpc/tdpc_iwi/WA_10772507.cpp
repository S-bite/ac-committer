#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(310, vector<int>(310, 0));
    rep(i, n - 3)
    {
        if (s.substr(i, 3) == "iwi")
        {
            dp[i][i + 2] = 1;
        }
    }
    rep(len, 3, n)
    {
        rep(l, n - len)
        {
            int r = l + len;
            if ((s.substr(l, 2) == "iw" && s.substr(r, 1) == "i" && dp[l + 2][r - 1] == r - l - 2) || (s.substr(l, 1) == "i" && s.substr(r - 1, 2) == "wi" && dp[l + 1][r - 2] == r - l - 2))
            {
                dp[l][r] = r - l + 1;
            }
            rep(j, l, r + 1)
            {
                dp[l][r] = max(dp[l][r], dp[l][j] + dp[j][r]);
            }
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}