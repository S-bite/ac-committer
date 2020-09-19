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
    ll n, x, m;
    cin >> n >> x >> m;
    VI buf(m, -1);
    ll cur = x;

    ll ans = 0;
    VL log(m, 0);
    rep(i, n)
    {
        ans += cur;
        log[i] = cur;
        buf[cur] = i;
        cur = (cur * cur) % m;

        if (buf[cur] != -1)
        {
            // cerr << cur << endl;
            int start = buf[cur];
            ll rem = n - i - 1;
            ll tmp = 0;
            rep(j, start, i + 1)
            {
                //  cerr << j << " " << log[j] << endl;
                tmp += log[j];
            }
            //cerr << (i - start + 1) << endl;
            ans += tmp * (rem / (i - start + 1));
            rem %= (i - start + 1);
            rep(j, rem)
            {
                ans += cur;
                cur = (cur * cur) % m;
            }
            cout << ans << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}