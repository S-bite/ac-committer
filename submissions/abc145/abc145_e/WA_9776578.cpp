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
    int n, t;
    cin >> n >> t;

    vector<pair<int, int>> m(n);
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    vector<vector<int>> dp(6000, vector<int>(2, 0));
    rep(i, n)
    {
        auto next = dp;
        rep(j, 6000)
        {
            if (j - 1 >= 0)
            {
                next[j][1] = max(dp[j][1], dp[j - 1][0] + b[i]);
            }
            if (j - a[i] < 0)
                continue;
            next[j][0] = max(dp[j][0], dp[j - a[i]][0] + b[i]);
        }
        dp = next;
    }
    cout << dp[t][1] << endl;

    return 0;
}
