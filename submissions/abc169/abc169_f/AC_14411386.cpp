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
const ll MOD = 998244353;

int main()
{
    int n, s;
    cin >> n >> s;
    VI dp(3030, 0);
    dp[0] = 1;
    rep(i, n)
    {
        int a;
        cin >> a;
        auto next = dp;
        rep(j, 3030)
        {
            next[j] *= 2;
            next[j] %= MOD;
            if (j - a >= 0)
            {
                next[j] += dp[j - a];
            }
            next[j] %= MOD;
        }
        dp = next;
    }
    cout << dp[s] << endl;
}