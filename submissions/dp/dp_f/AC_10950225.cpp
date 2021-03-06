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
    string ans;
    rep(i, h) rep(j, w)
    {

        chmax(dp[i + 1][j + 1], dp[i][j + 1]);
        chmax(dp[i + 1][j + 1], dp[i + 1][j]);
        if (s[i] == t[j])
        {
            chmax(dp[i + 1][j + 1], dp[i][j] + 1);
        }
    }
    int cur = dp[h][w];
    int y = h;
    int x = w;
    while (cur != 0)
    {
        //  cerr << y << " " << x << endl;
        if (dp[y - 1][x - 1] == dp[y][x] - 1 && dp[y][x - 1] == dp[y][x] - 1 && dp[y - 1][x] == dp[y][x] - 1)
        {
            ans += t[x - 1];
            x--;
            y--;
            cur = dp[y][x];
        }
        else if (dp[y][x - 1] == dp[y][x])
        {
            x--;
        }
        else
        {
            y--;
        }
    }

    reverse(ALL(ans));
    cout << ans << endl;
    return 0;
}
