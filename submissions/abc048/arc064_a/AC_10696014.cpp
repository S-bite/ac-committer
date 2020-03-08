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
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    rep(i, n) { cin >> v[i]; }
    auto tmp = v;
    ll ans1 = 0, ans2 = 0;
    rep(i, 1, n)
    {
        if (v[i - 1] + v[i] > x)
        {
            ll diff = (v[i - 1] + v[i]) - x;
            ans1 += diff;
            v[i] = max(0ll, v[i] - diff);
        }
    }

    cout << ans1 << endl;

    return 0;
}
