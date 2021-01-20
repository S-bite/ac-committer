#include <bits/stdc++.h>
#include <atcoder/all>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define contain(x, y) (x.find(y) != x.end())

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
    int n, m;
    cin >> n >> m;
    scc_graph g(n);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g.add_edge(a, b);
        g.add_edge(b, a);
    }
    cout << g.scc().size() - 1 << endl;
}