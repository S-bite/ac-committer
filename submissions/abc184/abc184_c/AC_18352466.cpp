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
int sx, sy, gx, gy;

int rec(int x, int y, int depth)
{
    if (depth == 3) {
        return 3;
    }
    if (x == 0 && y == 0) {
        return depth;
    }
    if (abs(x) == abs(y)) {
        return depth + 1;
    }
    int ret = IINF;
    if ((x + y) % 2 == 0)
        ret = depth + 2;
    rep(i, -3, 3 + 1)
    {
        rep(j, -3, 3 + 1)
        {
            if (abs(i) + abs(j) <= 3) {
                chmin(ret, rec(x + i, y + j, depth + 1));
            }
        }
    }
    return ret;
}

int main()
{
    cin >> sx >> sy >> gx >> gy;
    gx -= sx;
    gy -= sy;
    cout << rec(gx, gy, 0) << endl;
    return 0;
}
