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
    vector<long double> v(n);
    rep(i, n) cin >> v[i];
    long double s1 = 0, s2 = 0, s3 = 0;
    rep(i, n)
    {
        s1 += fabsl(v[i]);
        s2 += fabsl(v[i]) * fabsl(v[i]);
        s3 = max(s3, fabsl(v[i]));
    }
    s2 = sqrtl(s2);
    cout << fixed << setprecision(18) << s1 << endl;
    cout << fixed << setprecision(18) << s2 << endl;
    cout << fixed << setprecision(18) << s3 << endl;
    return 0;
}