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
const int IINF = 1 << 28;
const ll INF = 1ll << 60;
const ll MOD = 1000000007;
int main()
{
    ll n, q;
    cin >> n >> q;
    bool trans = false;
    VL y(n), x(n);
    rep(i, n)
    {
        y[i] = i;
        x[i] = i;
    }
    rep(i, q)
    {
        int ty;
        cin >> ty;
        if (ty == 3)
        {
            swap(x, y);
            trans ^= true;
            continue;
        }
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (ty == 4)
        {
            if (trans == false)
                cout << y[a] * n + x[b] << endl;
            else
                cout << y[a] + x[b] * n << endl;
        }
        else if (ty == 1)
        {
            swap(y[a], y[b]);
        }
        else
        {
            swap(x[a], x[b]);
        }
    }
    return 0;
}
