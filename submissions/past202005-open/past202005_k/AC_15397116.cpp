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
int main()
{
    int n;
    int q;
    cin >> n >> q;
    VI par(n + 1);
    VI top(n + 1);

    rep(i, 1, n + 1)
    {
        par[i] = -i;
        top[i] = i;
    }
    rep(i, q)
    {
        int a, b, c;
        cin >> a >> c >> b;
        int tmp = par[b];
        par[b] = top[c];
        top[c] = top[a];
        top[a] = tmp;
    }
    map<int, int> mp;
    rep(i, 1, n + 1)
    {
        int cur = top[i];
        while (cur > 0)
        {
            mp[cur] = i;
            cur = par[cur];
        }
    }
    rep(i, 1, n + 1)
    {
        cout << mp[i] << endl;
    }

    return 0;
}
