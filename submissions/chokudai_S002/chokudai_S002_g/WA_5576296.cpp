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

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(int argc, char const *argv[])
{
    ll n;
    cin >> n;
    ll a[n], b[n];
    ll ans = 0;
    map<pair<int, int>, bool> mp;
    rep(i, n) cin >> a[i] >> b[i];
    rep(i, n)
    {
        cout << gcd(max(a[i], b[i]), min(a[i], b[i])) << endl;
    }
    cout << ans << endl;
    return 0;
}
