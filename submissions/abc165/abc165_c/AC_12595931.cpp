#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
random_device rnd;
mt19937 mt(rnd());

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;
int n, m, q;
VVI req;
ll ans = -1;

ll calc(VI &A)
{
    ll ret = 0;
    for (auto &&x : req)
    {
        int a = x[0];
        int b = x[1];
        int c = x[2];
        int d = x[3];
        a--;
        b--;
        if (A[b] - A[a] == c)
        {
            ret += d;
        }
    }
    return ret;
}

void dfs(int cur, VI A)
{
    if (cur == n)
    {
        chmax(ans, calc(A));
        return;
    }
    int start;
    if (A.size() == 0)
    {
        start = 1;
    }
    else
    {
        start = A.back();
    }
    rep(i, start, m + 1)
    {
        A.push_back(i);
        dfs(cur + 1, A);
        A.pop_back();
    }
}

int main()
{
    cin >> n >> m >> q;
    req = VVI(q, vector<int>(4));
    rep(i, q)
    {
        cin >> req[i][0] >> req[i][1] >> req[i][2] >> req[i][3];
    }
    dfs(0, {});
    cout << ans << endl;
    return 0;
}