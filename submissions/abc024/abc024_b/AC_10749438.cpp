#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
const lld PI = acos(-1);

int main()
{
    ll n, t;
    cin >> n >> t;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    ll ans = 0;
    int cur = 0;
    rep(i, n)
    {
        if (cur <= v[i])
        {
            cur = v[i] + t;
            ans += t;
        }
        else
        {
            ans += v[i] + t - cur;
            cur = v[i] + t;
        }
    }
    cout << ans << endl;
    return 0;
}
