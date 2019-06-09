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
#define MOD (ll)(1e9 + 7)
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int dp[n + 5];
    map<int, bool> mp;
    rep(i, m)
    {
        int t;
        cin >> t;
        mp[t] = true;
    }
    if (mp[1] == true)
    {
        dp[1] = 0;
    }
    else
    {
        dp[1] = 1;
    }

    if (mp[2] == true)
    {
        dp[2] = 0;
    }
    else
    {
        dp[2] = 1 + dp[1];
    }
    rep(i, 3, n + 1)
    {
        if (mp[i] == true)
        {
            dp[i] = 0;
        }
        else
        {
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        }
    }
    cout << dp[n] << endl;
    return 0;
}