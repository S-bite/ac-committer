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
    int n, t;
    cin >> n >> t;

    vector<pair<int, int>> m(n);
    vector<int> a(n), b(n);
    rep(i, n)
    {

        cin >> a[i] >> b[i];
        m[i] = {a[i], b[i]};
    }
    sort(ALL(m));
    vector<vector<int>> dp(6000, vector<int>(2, 0));
    rep(i, n)
    {
        auto next = dp;
        rep(j, t + 1)
        {
            int ca = m[i].first;
            int cb = m[i].second;
            if (j - 1 >= 0)
            {
                next[j][1] = max(dp[j][1], dp[j - 1][0] + cb);
            }
            if (j - ca >= 0)
            {
                next[j][0] = max(dp[j][0], dp[j - ca][0] + cb);
            }
        }
        dp = next;

       /* rep(j, t) cerr << dp[j][0] << " ";
        cerr << endl;
        cerr << "---------" << endl;
        rep(j, t) cerr << dp[j][1] << " ";
        cerr << endl;
   */ }
       cout << dp[t][1] << endl;

       return 0;
}
