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

    ll n, m;
    cin >> n >> m;
    if (m == 0)
    {
        cout << 1 << endl;
        return 0;
    }
    VL v;
    rep(i, m)
    {
        ll t;
        cin >> t;
        v.push_back(t);
    }
    v.push_back(0);
    v.push_back(n + 1);
    sort(ALL(v));

    ll ans = IINF;
    rep(i, m + 1)
    {
        ll diff = v[i + 1] - v[i] - 1;
        if (diff == 0)
            continue;
        cerr << ans << " " << diff << endl;
        ans = min(ans, diff);
    }
    if (ans == IINF)
    {
        cout << 0 << endl;
        return 0;
    }
    cerr << ans << endl;
    ll cnt = 0;
    rep(i, m + 1)
    {
        ll diff = v[i + 1] - v[i] - 1;
        if (diff == 0)
            continue;
        cnt += (diff + ans - 1) / ans;
    }
    cout << cnt << endl;

    return 0;
}