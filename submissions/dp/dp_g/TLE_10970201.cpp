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
VI dp(101010, -1);
map<int, VI> g;

int dfs(int cur)
{
    int ret = 0;
    for (auto x : g[cur])
    {
        chmax(ret, 1 + dfs(x));
    }
    dp[cur] = ret;
    return ret;
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
    }
    rep(i, n)
    {
        if (dp[i] == -1)
        {
            dfs(i);
        }
    }
    int ans = -1;
    rep(i, n) ans = chmax(ans, dp[i]);
    cout << ans << endl;
    return 0;
}
