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
    ll a, b, k;
    cin >> a >> b >> k;
    ll c = a - k;
    if (c < 0)
    {
        a = 0;
        b -= -c;
        if (b < 0)
            b = 0;
    }
    else
    {
        a -= k;
    }
    cout << a << " " << b << endl;
    return 0;
}
