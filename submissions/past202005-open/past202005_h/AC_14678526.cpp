#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
random_device rnd;
mt19937 mt(rnd());
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1000000007;

int main()
{
    int n, l;
    cin >> n >> l;
    vector<bool> blocked(l + 10, false);
    rep(i, n)
    {
        int t;
        cin >> t;
        blocked[t] = true;
    }
    int t1, t2, t3;
    cin >> t1 >> t2 >> t3;
    VI dp(l + 10, IINF);
    dp[0] = 0;
    rep(i, l)
    {
        int c = t1;
        if (blocked[i])
        {
            c += t3;
        }
        chmin(dp[i + 1], dp[i] + c);

        chmin(dp[i + 2], dp[i] + c + t2);

        chmin(dp[i + 4], dp[i] + c + 3 * t2);
    }
    int ans = dp[l];
    rep(i, 1, 3 + 1)
    {
        if (l - i >= 0)
        {
            int c = (blocked[l - i] ? t3 : 0);
            chmin(ans, dp[l - i] + t1 / 2 + c + t2 / 2 + t2 * (i - 1));
        }
    }
    cout << ans << endl;
    return 0;
}
