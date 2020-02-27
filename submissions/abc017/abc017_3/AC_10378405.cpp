#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

const double EPS = 1e-3;
const double PI = 3.1415926535897932384626433832795028841971;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<ll> imos(m + 1, 0);
    ll sum = 0;
    rep(i, n)
    {
        int l, r, s;
        cin >> l >> r >> s;
        l--;
        r--;
        imos[l] += s;
        imos[r + 1] -= s;
        sum += s;
    }
    ll ans = 0;
    ll cur = 0;
    rep(i, m)
    {
        cur += imos[i];
        ans = max(ans, sum - cur);
    }
    cout << ans << endl;

    return 0;
}
