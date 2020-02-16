#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
const ll INF = 1ll << 60;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> v(s.size());
    rep(i, s.size()) v[i] = s[i] - '0';
    vector<vector<int>> dp(s.size() + 1, vector<int>(2, 0));
    dp[n - 1][0] = min(v[n - 1], 10 - v[n - 1]);
    dp[n - 1][1] = min(v[n - 1], 9 - v[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        dp[i][0] = min(v[i] + dp[i + 1][0], 10 - v[i] + dp[i + 1][1]);
        dp[i][1] = min(1 + v[i] + dp[i + 1][0], 9 - v[i] + dp[i + 1][1]);
    }
    ll ans = 1 + dp[0][0];
    ll cur = 0;
    rep(i, n)
    {
        cur += v[i];
        ll nowpay = cur + 1;
        nowpay += dp[i + 1][0];
        ans = min(ans, nowpay);
    }
    cout << ans << endl;

    return 0;
}