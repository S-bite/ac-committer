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
const long long INF = 1LL << 60;
using namespace std;
//0:41
int main(int argc, char const *argv[])
{
    int n, z, w;
    cin >> n >> z >> w;
    int a[n];
    rep(i, n) cin >> a[i];
    ll dp[n + 1][2];
    for (int i = n; i >= 0; i--)
    {
        int y = (i == 0) ? w : a[i - 1];
        dp[i][0] = -INF;
        dp[i][0] = max(dp[i][0], llabs(a[n - 1] - y));
        rep(j, i + 1, n + 1)
        {
            dp[i][0] = max(dp[i][0], dp[j][1]);
        }
        y = (i == 0) ? z : a[i - 1];
        dp[i][1] = INF;
        dp[i][1] = min(dp[i][1], llabs(a[n - 1] - y));
        rep(j, i + 1, n + 1)
        {
            dp[i][1] = max(dp[i][1], dp[j][0]);
        }

    }
    cout<<dp[0][0]<<endl;
    return 0;
}
