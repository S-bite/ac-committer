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
    int n;
    ll t;
    cin >> n >> t;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    if (n == 1) {
        if (a[0] <= t) {
            cout << a[0] << endl;
        } else {
            cout << 0 << endl;
        }
        return 0;
    }

    int r = n / 2;
    int l = n - r;
    vector<ll> v;
    v.push_back(0);
    rep(i, 1 << (r))
    {
        ll tmp = 0;
        rep(j, r)
        {
            if ((i >> j) & 1) {
                tmp += a[j];
            }
        }
        v.push_back(-tmp);
    }
    sort(ALL(v));
    ll ans = 0;
    rep(i, 1 << (l))
    {
        ll tmp = 0;
        rep(j, l)
        {
            if ((i >> j) & 1) {
                tmp += a[r + j];
            }
        }
        if (tmp > t)
            continue;
        chmax(ans, tmp - *lower_bound(ALL(v), -(t - tmp)));
    }
    cout << ans << endl;

    return 0;
}
