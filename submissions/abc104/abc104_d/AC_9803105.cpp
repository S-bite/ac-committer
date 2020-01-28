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

const ll MOD = 1e9 + 7;

ll mpow(int base, int n)
{
    if (n == 0)
    {
        return 1;
    }
    ll prev = mpow(base, n / 2);
    if (n % 2 == 0)
    {
        return (prev * prev) % MOD;
    }
    else
    {
        return (prev * prev * base) % MOD;
    }
}

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    vector<vector<ll>> dp(s.size() + 1, vector<ll>(3, 0)); //0:"A" 1:"A"
    dp[0][0] = 1;
    ll ans = 0;
    ll cur = 0;
    rep(i, s.size())
    {
        dp[i + 1] = dp[i];
        if (s[i] == 'A')
        {
            dp[i + 1][1] += mpow(3, cur); //dp[i][0];
        }
        else if (s[i] == 'B')
        {
            dp[i + 1][2] += dp[i][1];
        }
        else if (s[i] == 'C')
        {
            dp[i + 1][0] += dp[i][2];
            ans += dp[i][2];
        }
        else if (s[i] == '?')
        {
            dp[i + 1][1] += mpow(3, cur);
            dp[i + 1][2] += dp[i][1];
            dp[i + 1][0] += dp[i][2];

            dp[i + 1][0] += 2 * dp[i][0];
            dp[i + 1][1] += 2 * dp[i][1];
            dp[i + 1][2] += 2 * dp[i][2];

            ans += 2 * ans;
            ans += dp[i][2];
            cur++;
        }
        dp[i + 1][0] %= MOD;
        dp[i + 1][1] %= MOD;
        dp[i + 1][2] %= MOD;
        //cerr << dp[i + 1][0] << " " << dp[i + 1][1] << " " << dp[i + 1][2] << " " << ans << endl;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
