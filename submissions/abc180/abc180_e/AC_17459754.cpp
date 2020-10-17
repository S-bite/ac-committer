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
const int IINF = 1 << 28;
const ll INF = 1ll << 60;
const ll MOD = 1000000007;
// cf.http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3144506
const int maxn = 17;
int n, m;
int dist[maxn][maxn];
int dp[1 << maxn][maxn];

int dfs(int s, int v)
{

    if (dp[s][v] >= 0) {
        return dp[s][v];
    }
    //cerr << s << " " << v << endl;
    if (s == (1 << n) - 1 && v == 0) {
        //  cerr << "a" << endl;
        return dp[s][v] = 0;
    }

    int ans = IINF;
    rep(u, 0, n)
    {
        if (!(s >> u & 1)) {
            ans = min(ans, dfs(s | 1 << u, u) + dist[v][u]);
        }
    }

    dp[s][v] = ans;
    return ans;
}

int main()
{

    cin >> n;
    vector<vector<int>> v(n, vector<int>(3));
    rep(i, n)
    {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    memset(dp, -1, sizeof(dp));
    fill(dist[0], dist[0] + maxn * maxn, IINF);

    rep(i, n)
    {
        rep(j, n)
        {
            if (i == j)
                continue;
            dist[i][j] = abs(v[j][0] - v[i][0]) + abs(v[j][1] - v[i][1]) + max(0, v[j][2] - v[i][2]);
            //   cerr << dist[i][j] << endl;
        }
    }

    int ans = dfs(0, 0);
    cout << ans << endl;
}
