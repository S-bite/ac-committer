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

int n;

bool check(int pos, VI &b, VI &v)
{
    int cur = 0;
    rep(i, n)
    {
        cur ^= v[i];
    }
    rep(i, n)
    {
        cur ^= v[i];
        if (((cur >> pos) & 1) != b[i])
        {
            return false;
        }
        cur ^= v[i];
    }
    return true;
}

int main()
{
    cin >> n;
    VI v(n);
    rep(i, n) cin >> v[i];
    VI b(n, 0);
    VI ans(n, 0);
    rep(i, 30)
    {
        b[0] = 0;
        rep(j, 1, n)
        {
            b[j] = (((v[j] ^ v[0]) >> i) & 1);
        }
        if (check(i, b, v) == false)
        {
            rep(j, n)
            {
                b[j] ^= 1;
            }
            assert(check(i, b, v));
        }
        rep(j, n)
        {
            ans[j] |= b[j] << i;
        }
    }
    int cur = 0;
    rep(i, n)
    {
        cur ^= ans[i];
        cout << ans[i] << " ";
    }
    cout << endl;
    rep(i, n)
    {
        //   cerr << (cur ^ ans[i]) << endl;
    }
    return 0;
}