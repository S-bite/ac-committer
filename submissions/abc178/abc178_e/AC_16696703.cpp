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
    cin >> n;
    vector<pair<ll, ll>> v(n), w(4);
    rep(i, n) cin >> v[i].first >> v[i].second;
    w[0] = v[0];
    w[1] = v[0];
    w[2] = v[0];
    w[3] = v[0];
    rep(i, n)
    {
        rep(j, 4)
        {
            ll x = (j & 1) ? 1 : -1;
            ll y = (j & 2) ? 1 : -1;
            if (x * w[j].first + y * w[j].second > x * v[i].first + y * v[i].second)
            {
                w[j] = v[i];
            }
        }
    }
    ll ans = 0;
    rep(i, n)
    {
        rep(j, 4)
        {
            chmax(ans, llabs(v[i].first - w[j].first) + llabs(v[i].second - w[j].second));
        }
    }
    cout << ans << endl;
    return 0;
}