#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (a); i < (b); ++i)
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
vector<ll> ans;

bool ok(ll n, ll k)
{
    // assert(2 <= k && k <= n);
    while (n % k == 0 && k != 1)
        n /= k;
    //cerr << k << " " << n % k << endl;
    return n % k == 1ll;
}
int main()
{
    ll n;
    cin >> n;
    int ans = 0;
    rep(p, 1, n + 1)
    {
        if (n < p * p)
            break;
        if (n % p == 0)
        {
            if (ok(n, p))
                ans++;
            if (p != n / p)
            {
                if (ok(n, n / p))
                    ans++;
            }
        }
    }
    n--;
    rep(p, 1, n + 1)
    {
        if (n < p * p)
            break;
        if (n % p == 0)
        {
            if (ok(n + 1, p))
                ans++;
            if (p != n / p)
            {
                if (ok(n + 1, n / p))
                    ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
