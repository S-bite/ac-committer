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
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    ll ans = 0;
    while (x < y) {
        if ((lld)x < (lld)(x + b) / (lld)(a) && x < (lld)y / (lld)a) {
            x *= a;
            ans++;
            if (x + 1 == y) {
                break;
            }
        } else {
            if (x + 1 == y)
                break;
            ans += (y - x + b - 1) / b - 1;

            break;
        }
    }
    cout << ans << endl;
    return 0;
}