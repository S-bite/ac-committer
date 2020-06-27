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

int main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    VL a(n), b(m);
    VL sa(n + 1, 0), sb(m + 1, 0);
    rep(i, n)
    {
        cin >> a[i];
        sa[i + 1] = sa[i] + a[i];
    }
    rep(i, m)
    {
        cin >> b[i];
        sb[i + 1] = sb[i] + b[i];
    }
    ll ans = 0;
    rep(i, k + 1)
    {
        ll cur = upper_bound(ALL(sa), i) - sa.begin() - 1;
        cur += upper_bound(ALL(sb), k - i) - sb.begin() - 1;
        //cerr << i << " " << cur << endl;
        chmax(ans, cur);
    }
    cout << ans << endl;
    return 0;
}