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
    ll n, a, b, c, d, e;
    cin >> n >> a >> b >> c >> d >> e;
    ll m = min({a, b, c, d, e});
    cout << (4 + (n + m - 1) / m) << endl;

    return 0;
}
