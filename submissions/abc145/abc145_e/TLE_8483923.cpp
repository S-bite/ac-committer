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
    int n, t;
    cin >> n >> t;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    vector<vector<int>> dp(n + 1, vector<int>(t + 5, 0));
    map<pair<int, int>, map<int, int>> mp;
    rep(i, n)
    {
        rep(j, t + 5)
        {
            //cerr << "change " << dp[i + 1][j] << "->" << dp[i][j] << endl;
            dp[i + 1][j] = dp[i][j];
            mp[{i + 1, j}] = mp[{i, j}];
        }
        rep(j, t)
        {
            if (a[i] + j < t)
            {
                if (dp[i + 1][j + a[i]] < dp[i][j] + b[i])
                {
                    dp[i + 1][j + a[i]] = dp[i][j] + b[i];
                    mp[{i + 1, j + a[i]}] = mp[{i, j}];
                    mp[{i + 1, j + a[i]}][i] = true;
                }
            }
        }
    }
    int ans = 0;
    rep(j, t)
    {
        //cerr << dp[n][j] << endl;
        rep(i, n)
        {
            //cerr << mp[{n, j}][i] << " ";
            int tt = 0;
            if (mp[{n, j}][i] == false)
            {

                tt = b[i];
            }
            ans = max(ans, dp[n][j] + tt);
        }
        //cerr << endl;
    }
    cout << ans << endl;
    return 0;
}
