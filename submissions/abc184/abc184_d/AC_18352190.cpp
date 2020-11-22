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
double dp[101][101][101];
double rec(int a, int b, int c, int d)
{
    if (a < 0 || b < 0 || c < 0) {
        return 0;
    }
    if (d >= 1 && (a == 100 || b == 100 || c == 100)) {
        //  dp[a][b][c] = 0;
        return 0;
    }
    if (a + b + c == 1) {
        if (dp[a][b][c] != -1)
            return dp[a][b][c];
        return 0;
    }
    if (dp[a][b][c] != -1) {
        return dp[a][b][c];
    }
    double tmp = 0;
    tmp += (rec(a - 1, b, c, d + 1)) * (double)(a - 1) / (double)(a - 1 + b + c);
    tmp += (rec(a, b - 1, c, d + 1)) * (double)(b - 1) / (double)(a - 1 + b + c);
    tmp += (rec(a, b, c - 1, d + 1)) * (double)(c - 1) / (double)(a - 1 + b + c);
    //cerr << a << " " << b << " " << c << " " << tmp << endl;

    dp[a][b][c] = tmp;
    return dp[a][b][c];
}
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    rep(i, 101)
    {
        rep(j, 101)
        {
            rep(k, 101)
            {
                dp[i][j][k] = -1;
            }
        }
    }
    dp[a][b][c] = 1.0;
    double ans = 0;
    int num = 0;
    cerr << rec(99, 99, 100, 0) << endl;
    rep(i, 100)
    {
        rep(j, 100)
        {
            ans += rec(100, i, j, 0) * (100 - a + i - b + j - c);
            ans += rec(i, 100, j, 0) * (i - a + 100 - b + j - c);
            ans += rec(i, j, 100, 0) * (i - a + j - b + 100 - c);
        }
    }
    cerr << fixed << setprecision(18) << dp[0][0][99] << endl;

    cout << fixed << setprecision(18) << ans << endl;
    return 0;
}
