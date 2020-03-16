#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;
int main(int argc, char const *argv[])
{
    string s, t;
    cin >> s >> t;
    int h = s.size();
    int w = t.size();
    VVI dp(h + 1, VI(w + 1, 0));
    vector<vector<string>> ans(h + 1, vector<string>(w + 1, ""));
    rep(i, h) rep(j, w)
    {

        if (dp[i + 1][j + 1] < dp[i][j + 1])
        {
            chmax(dp[i + 1][j + 1], dp[i][j + 1]);

            ans[i + 1][j + 1] = ans[i][j + 1];
        }
        if (dp[i + 1][j + 1] < dp[i + 1][j])
        {
            chmax(dp[i + 1][j + 1], dp[i + 1][j]);
            ans[i + 1][j + 1] = ans[i + 1][j];
        }
        if (s[i] == t[j])
        {
            chmax(dp[i + 1][j + 1], dp[i][j] + 1);
            ans[i + 1][j + 1] = ans[i][j] + s[i];
        }
    }

    cout << ans[h][w] << endl;
    return 0;
}
