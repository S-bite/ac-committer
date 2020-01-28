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
const int IINF = (1 << 30);

int main(int argc, char const *argv[])
{
    int n, ma, mb;
    cin >> n >> ma >> mb;
    vector<int> a(n), b(n), c(n);
    rep(i, n) cin >> a[i] >> b[i] >> c[i];
    vector<vector<int>> dp(500, vector<int>(500, IINF));
    dp[0][0] = 0;
    rep(i, n)
    {
        auto next = dp;
        rep(j, 500)
        {
            rep(k, 500)
            {
                if (j - a[i] < 0 || k - b[i] < 0)
                {
                    continue;
                }
                next[j][k] = min(next[j][k], dp[j - a[i]][k - b[i]] + c[i]);
            }
        }
        dp = next;
    }
    int ans = IINF;
    rep(i, 1, 500)
    {
        rep(j, 1, 500)
        {
            if (i % ma == 0 && j % mb == 0 && i / ma == j / mb)
            {
                ans = min(ans, dp[i][j]);
            }
        }
    }
    if (ans == IINF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}
