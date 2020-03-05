#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
int main()
{
    ll a, b, c, d, e, f, g;
    cin >> a >> b >> c >> d >> e >> f >> g;
    ll ans = 0;
    ans += b;
    ans += (a / 2) * 2;
    ans += (d / 2) * 2;
    ans += (e / 2) * 2;
    a %= 2;
    d %= 2;
    e %= 2;
    if (a == 1 && d == 1 && e == 1)
        ans++;

    cout << ans << endl;
    return 0;
}