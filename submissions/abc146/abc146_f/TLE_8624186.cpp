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
    vector<vector<int>> move(n + 1, vector<int>(0));
    dp[0] = 0;
    rep(i, n)
    {
        auto newdp = dp;
        rep(j, 1, m + 1)
        {
            if (i + j > n || s[i + j] == '1')
            {
                continue;
            }
            if (dp[i] + 1 < newdp[i + j])
            {
                newdp[i + j] = dp[i] + 1;
                move[i + j] = move[i];
                move[i + j].push_back(j);
            }
        }
        dp = newdp;
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
        rep(i, move[n].size())
        {
            cout << move[n][i] << " ";
        }
        cout << endl;
        return 0;
    }
    return 0;
}
