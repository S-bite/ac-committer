#include <bits/stdc++.h>
#define ll long long

#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#ifdef DEBUG
#define line(i) cout << "[" << __LINE__ << "] ";
#define dump(i) cout << #i ":" << i << " ";
#define dumpl(i) cout << #i ":" << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
using namespace std;
int g[2000][2000], sum[2000][2000];
int main(int argc, char const *argv[])
{

    int n, k;
    cin >> n >> k;
    rep(i, n)
    {
        int x, y;
        char c;
        cin >> x >> y >> c;
        if (c == 'W')
            x += k;
        g[y % (2 * k)][x % (2 * k)]++;
    }
    rep(i, 2 * k) rep(j, 2 * k)
    {
        sum[i][j] = g[i][j];
        if (j != 0)
            sum[i][j] += sum[i][j - 1];
    }
    rep(i, 2 * k) rep(j, 2 * k)
    {
        if (i != 0)
            sum[i][j] += sum[i - 1][j];
    }
    int ans = -1, all = sum[2 * k - 1][2 * k - 1];
    rep(j, k) rep(i, k)
    {

        int now = sum[i][j];
        now += sum[2 * k - 1][j] - sum[i + k][j];
        now += sum[i][2 * k - 1] - sum[i][j + k];
        now += sum[i + k][j + k] - sum[i][j + k] - sum[i + k][j] + sum[i][j];
        now += sum[2 * k - 1][2 * k - 1] - sum[2 * k - 1][j + k] - sum[i + k][2 * k - 1] + sum[i + k][j + k];
        ans = max({ans, now, all - now});
    }

    cout << ans << endl;

    return 0;
}
