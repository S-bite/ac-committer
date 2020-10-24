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

int check(int a, int b, ll n)
{

    ll cur = 1;
    rep(i, a)
    {
        cur *= 3;
        if (cur > n) {
            return -1;
        }
    }
    ll tmp = 1;
    rep(j, b)
    {
        tmp *= 5;
        if (tmp > n) {
            return -1;
        }
    }
    cur += tmp;
    assert(cur > 0);
    if (cur > n) {
        return -1;
    }
    if (cur == n) {
        return 1;
    } else {
        return 0;
    }
}

int main()
{

    ll n;
    cin >> n;
    rep(i, 1, 100)
    {
        rep(j, 1, 100)
        {
            ll ret = check(i, j, n);
            if (ret == -1) {
                break;
            }

            if (ret == 1) {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}