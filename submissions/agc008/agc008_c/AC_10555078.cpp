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
    ll ans1 = 0, ans2 = 0, tmp = 0;
    ans1 += b;
    tmp = min({1ll, a, d, e});
    ans1 += tmp * 3;
    ans1 += ((d - tmp) / 2) * 2;
    ans1 += ((e - tmp) / 2) * 2;
    ans1 += ((a - tmp) / 2) * 2;

    ans2 += b;
    tmp = 0;
    ans2 += tmp * 3;
    ans2 += ((d - tmp) / 2) * 2;
    ans2 += ((e - tmp) / 2) * 2;
    ans2 += ((a - tmp) / 2) * 2;

    cout << max(ans1, ans2) << endl;
    return 0;
}