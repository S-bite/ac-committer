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
    ll n;
    cin >> n;
    ll ans = 2 * (n / 11);
    n -= ans / 2 * 11;
    cerr << n << endl;
    if (n <= 6)
        ans += 1;
    else
        ans += 2;
    cout << ans << endl;
    return 0;
}