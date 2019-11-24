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

bool ok(ll a, ll b, ll x, ll n)
{
    if (n == 0)
        return true;
    ll d = 0;
    ll cost = n * a;
    while (n != 0)
    {
        n /= 10;
        d++;
    }
    cost += b * d;
    return cost <= x;
}

int main(int argc, char const *argv[])
{
    ll a, b, x;
    cin >> a >> b >> x;
    ll l = -1;
    ll r = 1e9 + 1;
    while (l + 1 != r)
    {
        ll med = (l + r) / 2;
        if (ok(a, b, x, med))
        {
            l = med;
        }
        else
        {
            r = med;
        }
    }
    cout << l << endl;
    return 0;
}
