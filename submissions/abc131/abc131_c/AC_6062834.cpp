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

ll divnum(ll a, ll b, ll n)
{
    return (b / n - (a - 1) / n);
}

ll gcd(ll a, ll b)
{
    if (b > a)
    {
        ll tmp = a;
        a = b;
        b = tmp;
    }

    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

int main(int argc, char const *argv[])
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    cerr << divnum(a, b, c) << endl;
    cerr << divnum(a, b, d) << endl;
    cerr << divnum(a, b, c * d) << endl;
    ll ans = (b - a + 1) - (divnum(a, b, c) + divnum(a, b, d) - divnum(a, b, lcm(c, d)));
    cout << ans << endl;

    return 0;
}
