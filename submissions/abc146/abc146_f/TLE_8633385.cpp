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

#define INF (1ll << 60)
int main(int argc, char const *argv[])
{
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<ll> dp(n + 1, INF);
    vector<int> diff(n + 1, -1);
    dp[0] = 0;

    int mmove = 0;

    rep(i, n)
    {
        if (mmove < i)
        {
            break;
        }
        if (dp[i] == INF || s[i] == '1')
        {
            continue;
        }
        //auto newdp = dp;
        rep(j, 1, m + 1)
        {
            if (i + j > n)
                break;
            if (s[i + j] == '1' || dp[i + j] != INF)
            {
                continue;
            }
            if (dp[i] + 1 < dp[i + j])
            {
                dp[i + j] = dp[i] + 1;
                diff[i + j] = j;
                mmove = max(mmove, (int)(i + j));
            }
        }
        //dp = newdp;
        if (dp[n] != INF)
        {
            break;
        }
    }
    if (dp[n] == INF)
    {
        cout << -1 << endl;
        return 0;
    }
    else
    {
        int cur = n;
        vector<int> ans(dp[n], 0);
        rep(i, dp[n])
        {
            //cerr << cur << endl;
            ans[i] = diff[cur];
            cur -= diff[cur];
        }
        //rep(i, dp[n]) cerr << ans[i] << endl;
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        return 0;
    }
    return 0;
}
