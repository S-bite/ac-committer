#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    reverse(ALL(a));
    reverse(ALL(b));
    //first snuke second smeke
    vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(m + 1, {0, 0}));
    //vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    rep(i, n + 1)
    {
        rep(j, m + 1)
        {

            if ((i + j) % 2 == 0)
            {
                if (i - 1 >= 0)
                {
                    if (dp[i - 1][j].first + a[i] > dp[i][j].first)
                    {
                        dp[i][j] = dp[i - 1][j];
                        dp[i][j].first += a[i - 1];
                    }
                }
                if (j - 1 >= 0)
                {
                    if (dp[i][j - 1].first + b[j - 1] > dp[i][j].first)
                    {
                        dp[i][j] = dp[i][j - 1];
                        dp[i][j].first += b[j - 1];
                    }
                }
            }
            else
            {
                if (i - 1 >= 0)
                {
                    if (dp[i - 1][j].second + a[i - 1] > dp[i][j].second)
                    {
                        dp[i][j] = dp[i - 1][j];
                        dp[i][j].second += a[i - 1];
                    }
                }
                if (j - 1 >= 0)
                {
                    if (dp[i][j - 1].second + b[j - 1] > dp[i][j].second)
                    {
                        dp[i][j] = dp[i][j - 1];
                        dp[i][j].second += b[j - 1];
                    }
                }
            }
        }
    }
    if ((n + m) % 2 == 0)
    {
        cout << dp[n][m].first << endl;
    }
    else
    {
        cout << dp[n][m].second << endl;
    }
    return 0;
}
