#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
#ifdef DEBUG
#define line() cerr << "[" << __LINE__ << "] ";
#define dump(i) cerr << #i ": " << i << " ";
#define dumpl(i) cerr << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    vector<vector<bool>> dp(n + 1, vector<bool>(10101, false));
    dp[0][0] = true;
    rep(i, n)
    {
        dp[i + 1] = dp[i];
        rep(j, 10101)
        {
            if (j - p[i] < 0)
            {
                continue;
            }
            dp[i + 1][j] = dp[i + 1][j] || dp[i][j - p[i]];
        }
    }
    int ans = 0;
    rep(i, 10101)
    {
        if (dp[n][i])
            ans++;
    }
    cout << ans << endl;
    return 0;
}
