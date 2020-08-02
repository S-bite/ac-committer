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

bool ok(VL &v, ll l, int k)
{
    for (auto &x : v)
    {

        k -= (x + l - 1) / l - 1;
    }
    return k >= 0;
}

int main()
{
    int n, k;
    cin >> n >> k;
    VL v(n);
    rep(i, n)
    {
        cin >> v[i];
    }
    ll high = INF;
    ll low = 0;
    while (low + 1 != high)
    {
        ll mid = (high + low) / 2;
        if (ok(v, mid, k))
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    cout << high << endl;
    return 0;
}