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
int n, m;
VI a, b;

int memo[2000][2000];

int rec(int x, int y)
{
    if (x == n)
    {
        return m - y;
    }
    if (y == m)
    {
        return n - x;
    }
    if (memo[x][y] != -1)
    {
        return memo[x][y];
    }
    int cost1 = rec(x + 1, y + 1) + (a[x] == b[y] ? 0 : 1);
    int cost2 = 1 + rec(x, y + 1);
    int cost3 = 1 + rec(x + 1, y);
    memo[x][y] = min({cost1, cost2, cost3});
    return memo[x][y];
}

int main()
{
    rep(i, 2000) rep(j, 2000) memo[i][j] = -1;
    cin >> n >> m;
    rep(i, n)
    {
        int t;
        cin >> t;
        a.push_back(t);
    }
    rep(i, m)
    {
        int t;
        cin >> t;
        b.push_back(t);
    }
    cout << rec(0, 0) << endl;
    return 0;
}
