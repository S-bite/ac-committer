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
#define MOD 1000000007ll
using namespace std;

int ctoi(char c)
{
    return c - '0';
}
int main(int argc, char const *argv[])
{
    int dp[101010][13];
    rep(i, 101010) rep(j, 13) dp[i][j] = 0;
    string s;
    cin >> s;
    int cap = 1;
    if (s[s.size() - 1] == '?')
    {
        rep(i, 10)
            dp[s.size() - 1][i] = 1;
    }
    else
    {
        dp[s.size() - 1][ctoi(s[s.size() - 1])] = 1;
    }
    cap = (cap * 10) % 13;
    for (int i = s.size() - 2; i >= 0; i--)
    {
        if (s[i] == '?')
        {
            rep(j, 10)
            {
                rep(k, 13)
                {
                    dp[i][k] += dp[i + 1][(k - j * cap + 13 * j) % 13];
                    dp[i][k] %= MOD;
                }
            }
        }
        else
        {
            int j = ctoi(s[i]);
            rep(k, 13)
            {
                dp[i][k] += dp[i + 1][(k - j * cap + 13 * j) % 13];
                dp[i][k] %= MOD;
            }
        }
        //rep(k, 13)
        //    cerr
        //<< i << " " << k << " " << dp[i][k] << endl;

        cap = (cap * 10) % 13;
    }
    cout << dp[0][5] << endl;
    return 0;
}
