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
#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)

bool isok(ll now, ll k, vector<ll> &a)
{
    vector<ll> b(a.size(), 0);
    ll sum = 0;
    ll mx = -1;
    rep(i, a.size())
    {
        sum += (a[i] % now);
        mx = max(mx, a[i] % now);
    }
    if ((sum % now) != 0)
    {
        return false;
    }
    return sum - mx <= k;
}

int main()
{

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n, 0);
    ll cmax = 0;
    rep(i, n)
    {
        cin >> a[i];
        cmax += a[i];
    }
    //cmax /= n;
    for (ll i = cmax; i >= 1; i--)
    {
        if (isok(i, k, a))
        {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}