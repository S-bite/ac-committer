#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#ifdef DEBUG
#define line() cout << "[" << __LINE__ << "] ";
#define dump(i) cout << #i ": " << i << " ";
#define dumpl(i) cout << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
using namespace std;

ll one(ll n)
{
    if (n % 2 == 0)
        return 0;
    else
        return 1;
}
ll zero(ll n)
{
    return 1 - one(n);
}
int main(int argc, char const *argv[])
{
    ll a, b;
    cin >> a >> b;
    ll c = b - a;
    ll ans = 0;
    ll n = 1;
    rep(i, 40)
    {
        //if (n > c)
        //   break;
        ans += one(n) << i;
        ll q = c % n;
        if (((a >> i) & 1) == 1)
        {
            ans ^= one(a % (2 * n)) << i;
        }
        if (((b >> i) & 1) == 1)
        {
            ans ^= one(2 * n - (b % (2 * n)) - 1) << i;
        }
        n *= 2;
    }
    cout << ans << endl;

    return 0;
}

//010
//011
//100

//10000111100

//123456789 011001100