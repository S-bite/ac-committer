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

//count inside [sy,ey) [sx,ex)
int count_inside(VVI &sum, int sy, int sx, int ey, int ex)
{
    if (sy == ey || sx == ex)
        return 0;
    return sum[ey][ex] - sum[sy][ex] - sum[ey][sx] + sum[sy][sx];
}

int main()
{
    int n, k;
    cin >> n >> k;
    VVI black(2 * k, VI(2 * k, 0));
    VVI white(2 * k, VI(2 * k, 0));
    rep(i, n)
    {
        int x, y;
        char c;
        cin >> x >> y >> c;
        x %= 2 * k;
        y %= 2 * k;
        if (c == 'B')
        {
            black[y][x]++;
        }
        else
        {
            white[y][x]++;
        }
    }
    VVI bsum(2 * k + 1, VI(2 * k + 1, 0));
    VVI wsum(2 * k + 1, VI(2 * k + 1, 0));
    rep(i, 2 * k)
    {
        rep(j, 2 * k)
        {
            bsum[i + 1][j + 1] = bsum[i][j + 1] + bsum[i + 1][j] - bsum[i][j] + black[i][j];
            wsum[i + 1][j + 1] = wsum[i][j + 1] + wsum[i + 1][j] - wsum[i][j] + white[i][j];
        }
    }
    int ans = -1;
    rep(i, k)
    {
        rep(j, k)
        {
            int wnum = count_inside(wsum, 0, 0, i, j) + count_inside(wsum, i, j, i + k, j + k) + count_inside(wsum, i + k, j + k, 2 * k, 2 * k) + count_inside(wsum, i + k, 0, 2 * k, j) + count_inside(wsum, 0, j + k, i, 2 * k);
            int bnum = count_inside(bsum, 0, j, i, j + k) + count_inside(bsum, i, j + k, i + k, 2 * k) + count_inside(bsum, i, 0, i + k, j) + count_inside(bsum, i + k, j, 2 * k, j + k);
            chmax(ans, bnum + wnum);
            bnum = count_inside(bsum, 0, 0, i, j) + count_inside(bsum, i, j, i + k, j + k) + count_inside(bsum, i + k, j + k, 2 * k, 2 * k) + count_inside(bsum, i + k, 0, 2 * k, j) + count_inside(bsum, 0, j + k, i, 2 * k);
            wnum = count_inside(wsum, 0, j, i, j + k) + count_inside(wsum, i, j + k, i + k, 2 * k) + count_inside(wsum, i, 0, i + k, j) + count_inside(wsum, i + k, j, 2 * k, j + k);
            chmax(ans, bnum + wnum);
        }
    }
    cout << ans << endl;
    return 0;
}