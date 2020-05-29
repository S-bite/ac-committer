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
    int n;
    cin >> n;
    VI v(n);
    rep(i, n) cin >> v[i];
    sort(ALL(v));
    if (v[n - 1] - v[0] > 1)
    {
        cout << "No" << endl;
        return 0;
    }
    int low = v[0];
    int high = v[n - 1];
    if (high == low && low == n - 1)
    {
        cout << "Yes" << endl;
        return 0;
    }
    int highnum = 0;
    int lownum = 0;
    rep(i, n)
    {
        if (v[i] == high)
            highnum++;
    }
    lownum = n - highnum;
    cerr << high << " " << low << " " << highnum << " " << lownum << endl;
    if (high - lownum <= 0)
    {
        cout << "No" << endl;
        return 0;
    }
    if (2 * (high - lownum) <= highnum)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}