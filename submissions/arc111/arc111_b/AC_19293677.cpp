#include <bits/stdc++.h>
#include <atcoder/maxflow>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using namespace atcoder;
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

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n)
    {
        cin >> a[i] >> b[i];
    }
    int start = 200000 + 400000 + 1;
    int end = 200000 + 400000 + 2;

    mf_graph<int> g(200000 + 400000 + 3);
    rep(i, n)
    {
        g.add_edge(start, i, 1);
        g.add_edge(i, 200000 + a[i], 1);
        g.add_edge(i, 200000 + b[i], 1);
    }

    rep(i, 400000)
    {
        g.add_edge(1 + 200000 + i, end, 1);
    }
    cout << g.flow(start, end) << endl;

    return 0;
}