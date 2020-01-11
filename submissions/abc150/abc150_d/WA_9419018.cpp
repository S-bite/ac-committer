#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
ll gcd(ll a, ll b)
{
    cerr << a << " " << b << endl;
    if (a < b)
    {
        ll t = a;
        a = b;
        b = t;
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}

int main()
{
    ll n, m;
    cin >> n >> m;
    ll a[n];
    rep(i, n)
    {
        cin >> a[i];
    }
    ll g = a[0];
    rep(i, 1, n)
    {
        g = lcm(g, a[i]);
        if (g > 2 * m)
        {
            cout << 0 << endl;
            return 0;
        }
    }
    cerr << g << endl;
    ll ans = (2 * m) / g;
    ans = (ans + 1) / 2;
    cout << ans << endl;
    return 0;
}