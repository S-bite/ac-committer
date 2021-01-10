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

int solve(ll a, ll b)
{
    ll ans = b - a;
    int bits = 0;
    rep(i, 1, 64)
    {
        ll c = (b >> i);
        bits += (b >> (i - 1)) & 1;
        chmin(ans, abs(a - c) + i + bits);
    }
    return ans;
}

int main()
{
    ll a, b;
    cin >> a >> b;
    if (a >= b)
    {
        cout << a - b << endl;
        return 0;
    }
    ll ans = solve(a, b);
    rep(i, 10000)
    {
        chmin(ans, solve(a, b + (ll)i) + (ll)i);
    }
    cout << ans << endl;
    return 0;
}