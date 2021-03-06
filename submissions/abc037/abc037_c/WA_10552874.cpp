#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];
    ll ans = 0;
    rep(i, n)
    {
        if (i + 1 < k)
        {
            ans += v[i] * (i + 1);
        }
        else if (n - k <= i)
        {
            ans += v[i] * (n - i);
        }
        else
        {
            ans += v[i] * k;
        }
        assert(ans >= 0);
    }
    cout << ans << endl;
    return 0;
}