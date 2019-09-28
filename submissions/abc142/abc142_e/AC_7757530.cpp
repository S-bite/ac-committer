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
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    map<int, int> key;
    ll cost[m];
    rep(i, m)
    {
        int b;
        cin >> cost[i] >> b;
        key[i] = 0;
        rep(j, b)
        {
            int t;
            cin >> t;
            t--;
            key[i] |= (1 << t);
        }
    }
    ll dp[1 << n];
    ll INF = 1ll << 60;
    rep(i, 1 << n) dp[i] = INF;
    dp[0] = 0;
    rep(i, m)
    {
        rep(j, 1 << n)
        {
            dp[j | key[i]] = min(dp[j | key[i]], dp[j] + cost[i]);
        }
    }
    if (dp[(1 << n) - 1] != INF)
        cout << dp[(1 << n) - 1] << endl;
    else
        cout << -1 << endl;
    return 0;
}