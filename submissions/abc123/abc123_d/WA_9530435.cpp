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
    ll x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x), b(y), c(z);
    rep(i, x) cin >> a[i];
    rep(i, y) cin >> b[i];
    rep(i, z) cin >> c[i];
    sort(ALL(a), greater<ll>());
    sort(ALL(b), greater<ll>());
    sort(ALL(c), greater<ll>());
    vector<ll> tmp1, tmp2;
    rep(i, x) rep(j, y)
    {
        tmp1.push_back(a[i] + b[j]);
    }
    sort(ALL(tmp1), greater<ll>());
    rep(i, k)
    {
        rep(j, z)
        {
            tmp2.push_back(tmp1[i] + c[j]);
        }
    }
    sort(ALL(tmp2), greater<ll>());
    rep(i, k)
    {
        cout << tmp2[i] << endl;
    }
    return 0;
}
