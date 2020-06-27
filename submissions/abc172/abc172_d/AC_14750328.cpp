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

ll divnum(ll n)
{
    ll ret = 0;
    rep(i, 1, n + 1)
    {
        if (n % i == 0)
        {
            ret++;
        }
    }
    return ret;
}

ll f(ll n)
{
    ll ret = 0;
    rep(i, 1, n + 1)
    {
        ret += i * divnum(i);
    }
    return ret;
}

int main()
{
    ll n;
    cin >> n;
    ll ans = 0;
    ll sq = (ll)sqrt(n);
    // cerr << sq << endl;
    for (ll m = 1; m <= sq; m++)
    {
        ans += m * (m + (n / m)) * (n / m + 1 - m);
    }
    ans -= sq * (sq + 1) * (2 * sq + 1) / 6;
    cout << ans << endl;
    return 0;
}