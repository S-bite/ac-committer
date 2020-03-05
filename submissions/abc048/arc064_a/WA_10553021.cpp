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
    auto tmp = v;
    ll ans1 = 0, ans2 = 0;
    rep(i, n - 1)
    {
        ans1 += max(0ll, tmp[i] + tmp[i + 1] - k);
        tmp[i] -= max(0ll, tmp[i] + tmp[i + 1] - k);
    }
    tmp = v;
    rep(i, 1, n)
    {
        ans2 += max(0ll, tmp[i] + tmp[i - 1] - k);
        tmp[i] -= max(0ll, tmp[i] + tmp[i - 1] - k);
    }
    cerr << ans1 << " " << ans2 << endl;
    cout << min(ans1, ans2) << endl;

    return 0;
}