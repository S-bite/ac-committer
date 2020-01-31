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

    if (a < b)
        swap(a, b);
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

int main(int argc, char const *argv[])
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll p2 = 1;
    ll l = 1;
    while (a[0] % p2 == 0)
    {
        p2 *= 2;
    }
    p2 /= 2;
    rep(i, n)
    {
        if (a[i] % p2 != 0 || (a[i] % p2) % 2 == 0)
        {
            cout << 0 << endl;
            return 0;
        }
        else
        {
            l = lcm(l, a[i] / p2);
            cerr << a[i] / p2 << endl;
            if (l * p2 > m)
            {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    cerr << l << endl;
    cout << ((m / (l * (p2 / 2))) + 1) / 2 << endl;
    return 0;
}
