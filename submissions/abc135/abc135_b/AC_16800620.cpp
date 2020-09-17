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

bool is_sorted(VI &v)
{
    rep(i, v.size() - 1)
    {
        if (v[i] > v[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    VI v(n);
    rep(i, n) cin >> v[i];
    rep(i, n) rep(j, n)
    {
        swap(v[i], v[j]);
        if (is_sorted(v))
        {
            cout << "YES" << endl;
            return 0;
        }
        swap(v[i], v[j]);
    }
    cout << "NO" << endl;
    return 0;
}