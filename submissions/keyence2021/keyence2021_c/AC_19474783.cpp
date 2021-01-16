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

VL memo(5050, -1);
ll mpow(ll base, ll num)
{

    if (memo[num] != -1)
        return memo[num];
    if (num == 0)
    {
        return 1;
    }
    ll prev = mpow(base, num / 2);
    if (num % 2 == 0)
    {
        memo[num] = (prev * prev) % MOD;
        return (prev * prev) % MOD;
    }
    else
    {
        memo[num] = (((prev * prev) % MOD) * base) % MOD;
        return (((prev * prev) % MOD) * base) % MOD;
    }
}

int main()
{
    ll H, W, K;
    cin >> H >> W >> K;
    VVL tate(H, VL(W + 1, 0)), yoko(W, VL(H + 1, 0));
    ll x0 = mpow(3, H * W - K);
    ll x1 = mpow(3, H * W - K + 1);

    vector<string> g(H);
    rep(i, H)
    {
        g[i] = string(W, '@');
    }
    rep(i, K)
    {
        int y, x;
        char c;
        cin >> y >> x >> c;
        y--;
        x--;
        g[y][x] = c;
    }
    rep(i, H) rep(j, W)
    {
        tate[i][j + 1] = tate[i][j] + (g[i][j] == '@' ? 1 : 0);
        yoko[j][i + 1] = yoko[j][i] + (g[i][j] == '@' ? 1 : 0);
    }
    cerr << 123 << endl;
    VVL dp(H, VL(W, 0));
    dp[0][0] = 1;
    rep(i, H) rep(j, W)
    {
        if (j + 1 != W)
        {
            if (g[i][j] == '@')
            {
                int tmp = yoko[j][H] - yoko[j][i + 1];
                //cerr << i << " " << j << " " << tmp << endl;

                dp[i][j + 1] += dp[i][j] * 2 * mpow(3, tmp);
                dp[i][j + 1] %= MOD;
            }
            else
            {
                if (g[i][j] != 'D')
                {
                    int tmp = yoko[j][H] - yoko[j][i + 1];
                    //  cerr << i << " " << j << " " << tmp << endl;
                    dp[i][j + 1] += dp[i][j] * mpow(3, tmp);
                    dp[i][j + 1] %= MOD;
                }
            }
        }
        if (i + 1 != H)
        {
            if (g[i][j] == '@')
            {
                int tmp = tate[i][W] - tate[i][j + 1];
                //  cerr << i << " " << j << " " << tmp << endl;

                dp[i + 1][j] += dp[i][j] * 2 * mpow(3, tmp);
                dp[i + 1][j] %= MOD;
            }
            else
            {
                if (g[i][j] != 'R')
                {
                    int tmp = tate[i][W] - tate[i][j + 1];
                    //   cerr << i << " " << j << " " << tmp << endl;

                    dp[i + 1][j] += dp[i][j] * mpow(3, tmp);
                    dp[i + 1][j] %= MOD;
                }
            }
        }
    }
    if (g[H - 1][W - 1] == '@')
    {
        dp[H - 1][W - 1] *= 3;
        dp[H - 1][W - 1] %= MOD;
    }
    cout << dp[H - 1][W - 1] << endl;
    return 0;
}