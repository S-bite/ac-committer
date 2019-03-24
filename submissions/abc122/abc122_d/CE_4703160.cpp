#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
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
#define MOD 1000000007ll

char s(int i)
{
    char c[] = "ACGT";
    return c[i];
}

bool ok(int i, int j, int k, int l)
{
    return !((s(j) == 'A' && s(k) == 'G' && s(l) == 'C') ||
             (s(j) == 'G' && s(k) == 'A' && s(l) == 'C') ||
             (s(j) == 'A' && s(k) == 'C' && s(l) == 'G') ||
             (s(i) == 'A' && s(k) == 'G' && s(l) == 'C') ||
             (s(i) == 'A' && s(j) == 'G' && s(l) == 'C'));
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    ll ans = 0;
    ll dp[n + 100][4][4][4] = {};
    rep(i, 4) rep(j, 4) rep(k, 4)
    {
        dp[0][i][j][k] = 1;
    }
    dp[0][0][2][1] = 0;
    dp[0][0][1][2] = 0;
    dp[0][2][0][1] = 0;

    rep(step, 3, n)
    {
        rep(i, 4) rep(j, 4) rep(k, 4) rep(l, 4)
        {
            if (ok(i, j, k, l))
            {
                dp[step - 2][j][k][l] += dp[step - 3][i][j][k];
                dp[step - 2][j][k][l] %= MOD;
            }
            else
                cerr << s(i) << s(j) << s(k) << s(l) << endl;
        }
    }
    rep(i, 4) rep(j, 4) rep(k, 4)
    {
        ans += dp[n - 3][i][j][k];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
