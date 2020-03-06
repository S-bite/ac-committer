#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
#define chmin(x, y) x = min(x, y);
using namespace std;

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    sort(ALL(v));
    lld ans = 0;
    rep(i, n - k, n)
    {
        ans = (ans + v[i]) / 2;
    }
    cout << fixed << setprecision(18) << ans << endl;
    return 0;
}
