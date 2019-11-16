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
    map<pair<int, int>, int> mp;

    rep(i, n)
    {
        cin >> a[i] >> b[i];
        mp[{a[i], b[i]}]++;
    }
    vector<vector<int>> dp(n + 1, vector<int>(t, 0));
    rep(i, n)
    {
        rep(j, t)
        {
            //cerr << "change " << dp[i + 1][j] << "->" << dp[i][j] << endl;
            dp[i + 1][j] = dp[i][j];
        }
        rep(j, t)
        {
            if (a[i] + j < t)
            {
                if (dp[i + 1][j + a[i]] < dp[i][j] + b[i])
                {
                    dp[i + 1][j + a[i]] = dp[i][j] + b[i];
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
            bool ff = (j - a[i] < 0);
            int nn = mp[{a[i], b[i]}];
            rep(k, nn)
            {
                if (j - (k + 1) * a[i] < 0)
                {
                    ff = true;
                    break;
                }
                ff |= (dp[n][j] > dp[n][j - (k + 1) * a[i]] + (k + 1) * b[i]);
                if (k==100)break;
            }

            if (ff)
            {
                //  cerr << j << " " << i << " " << a[i] << " " << b[i] << endl;
                // cerr << dp[n][j] << " " << dp[n][j - a[i]] + b[i] << endl;
                tt = b[i];
            }
            ans = max(ans, dp[n][j] + tt);
        }
        //cerr << endl;
    }
    cout << ans << endl;
    return 0;
}
