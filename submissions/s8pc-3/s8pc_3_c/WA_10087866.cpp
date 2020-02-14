#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
const ll MOD = 1e9 + 7;

ll frac(int n)
{
    if (n == 0)
        return 1;
    return (n * frac(n - 1)) % MOD;
}

int main(int argc, char const *argv[])
{

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    rep(i, n)
    {
        cin >> v[i];
    }
    vector<map<int, int>> dp(256);
    dp[0][0] = 1;
    rep(i, n)
    {
        auto next = dp;
        rep(j, 256)
        {
            int to = j ^ v[i];
            for (auto x : dp[j])
            {
                next[to][x.first + 1] += x.second;
            }
        }
        dp = next;
    }
    ll ans = 0;
    for (auto x : dp[k])
    {
        ans += frac(x.first) * x.second;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
