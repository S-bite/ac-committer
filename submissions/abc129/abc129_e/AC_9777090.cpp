#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
const ll INF = (1ll << 60);
const ll MOD = 1e9 + 7;

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    vector<vector<ll>> dp(s.size(), vector<ll>(2, 0));
    dp[0][0] = 2;
    dp[0][1] = 1;

    rep(i, 1, s.size())
    {
        if (s[i] == '1')
        {
            dp[i][0] = (dp[i - 1][0] * 2) % MOD;
            dp[i][1] = (dp[i - 1][1] * 3 + dp[i - 1][0]) % MOD;
        }
        else
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = (dp[i - 1][1] * 3) % MOD;
        }
    }
    cout << (dp[s.size() - 1][0] + dp[s.size() - 1][1]) % MOD << endl;

    return 0;
}
