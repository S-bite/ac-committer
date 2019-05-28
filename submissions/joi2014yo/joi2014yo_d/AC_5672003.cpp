#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#ifdef DEBUG
#define line() cout << "[" << __LINE__ << "] ";
#define dump(i) cout << #i ": " << i << " ";
#define dumpl(i) cout << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
using namespace std;

int main(int argc, char const *argv[])
{

    const int MOD = 10007;
    map<char, int> mp;
    mp['J'] = 1;
    mp['O'] = 2;
    mp['I'] = 4;

    int n;
    string s;
    cin >> n >> s;
    int dp[n][1 << 3];
    rep(i, n + 1) rep(j, 1 << 3) dp[i][j] = 0;
    rep(i, 1 << 3)
    {
        if (((mp['J'] & i) != 0) && ((mp[s[0]] & i) != 0))
        {
            dp[0][i] = 1;
        }
    }
    rep(i, 0, n - 1)
    {
        rep(j, 1 << 3)
        {
            rep(k, 1 << 3)
            {
                if (((j & k) != 0) && ((k & mp[s[i + 1]]) != 0))
                {
                    dp[i + 1][k] += dp[i][j];
                    dp[i + 1][k] %= MOD;
                }
            }
        }
    }
    int ans = 0;
    rep(i, 1 << 3)
    {
        ans += dp[n - 1][i];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
