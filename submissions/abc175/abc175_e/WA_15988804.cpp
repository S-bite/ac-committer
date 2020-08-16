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
using VVVL = vector<VVL>;

using PII = pair<int, int>;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1000000007;

int main() {
    int h, w, n;
    cin>>h>>w>>n;
    VVL g(h, VL(w, 0));
    rep(i, n) {
        ll y, x, v;
        cin>>y>>x>>v;
        y--;x--;
        g[y][x]=v;
    }
    VVVL dp(h, VVL(w, VL(3, -1)));
    dp[0][0]={ g[0][0], g[0][0], g[0][0] };
    rep(i, h)rep(j, w) {
        rep(k, 3) {
            if (i+1<h) {
                dp[i+1][j][0]=max(dp[i+1][j][0], dp[i][j][k]);
                dp[i+1][j][1]=max(dp[i+1][j][1], dp[i][j][k]+g[i+1][j]);
            }
            if (j+1<w) {
                dp[i][j+1][k]=max(dp[i][j+1][k], dp[i][j][k]);
            }
            if (k<2 && j+1<w) {
                dp[i][j+1][k+1]=max(dp[i][j+1][k+1], dp[i][j][k]+g[i][j+1]);

            }
        }
    }
    cout<<max({ dp[h-1][w-1][0], dp[h-1][w-1][1], dp[h-1][w-1][2] })<<endl;
    return 0;
}