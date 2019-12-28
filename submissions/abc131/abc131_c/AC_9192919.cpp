#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
#ifdef DEBUG
#define line() cerr << "[" << __LINE__ << "] ";
#define dump(i) cerr << #i ": " << i << " ";
#define dumpl(i) cerr << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
using namespace std;

ll gcd(ll a, ll b)
{
    //cerr << a << " " << b << endl;
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

ll calc(ll a, ll b, ll n)
{
    return ((b - b % n) - ((a + ((n - a % n) % n)))) / n + 1;
}

int main(int argc, char const *argv[])
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    cerr << gcd(c, d) << endl;

    cerr << calc(a, b, c) << endl;
    cerr << calc(a, b, d) << endl;
    cerr << calc(a, b, c * d / gcd(c, d)) << endl;
    cout << (b - a + 1) - calc(a, b, c) - calc(a, b, d) + calc(a, b, c * d / gcd(c, d)) << endl;
    return 0;
}
