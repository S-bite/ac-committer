#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

int main(int argc, char const *argv[])
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<bool> dp(n + 1, false);
    dp[n] = true;
    rep(i, 300)
    {
        auto next = dp;
        rep(j, n + 1)
        {
            rep(k, 1, 4)
            {
                if (j - k >= 0 && j - k != a && j - k != b && j - k != c)
                {
                    next[j - k] = dp[j];
                }
            }
        }
        dp = next;
    }
    if (dp[0])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
