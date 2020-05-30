#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
random_device rnd;
mt19937 mt(rnd());

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;

int main()
{
    //N+1!!!!!!!!!!!!!!!!!!!
    int n;
    cin >> n;
    VL v(n + 1);
    VL num(n + 1, 0);
    rep(i, n + 1)
    {
        cin >> v[i];
    }
    ll cur = 0;
    for (int i = n; i >= 0; i--)
    {
        cur += v[i];
        num[i] += cur;
    }
    cur = 1;
    ll ans = 0;

    rep(i, n)
    {
        ans += cur;
        cerr << cur << " " << num[i] << endl;
        cur -= v[i];
        if (cur <= 0)
        {
            cout << -1 << endl;
            return 0;
        }
        cur *= 2;
        chmin(cur, num[i + 1]);
    }
    if (cur < v[n])
    {
        cout << -1 << endl;
        return 0;
    }
    ans += cur;
    cout << ans << endl;
    return 0;
}
