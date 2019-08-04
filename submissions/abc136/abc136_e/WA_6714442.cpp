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
    ll sum = 0;
    ll mx = -1;
    ll op = 0;
    vector<ll> b(a.size(), 0);
    rep(i, a.size())
    {
        sum += (a[i] % now);
        b[i] = a[i] % now;
    }
    if ((sum % now) != 0)
    {
        return false;
    }
    sort(ALL(b));
    ll bsum = 0;
    rep(i, a.size())
    {
        sum -= 2 * b[i];
        bsum += b[i];
        if (sum == 0)
            break;
    }
    //return true;
    return bsum <= k;
}
int main()
{

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n, 0);
    sort(ALL(a), greater<int>());
    ll cmax = 0;
    rep(i, n)
    {
        cin >> a[i];
        cmax += a[i];
    }

    vector<ll> d;
    ll i = 1;
    while (i * i <= cmax)
    {
        if (cmax % i == 0)
        {
            d.push_back(i);
            d.push_back(cmax / i);
        }
        i++;
    }
    sort(ALL(d), greater<ll>());
    for (auto now : d)
    {
        //   cerr << now << endl;
        //  ;
        if (isok(now, k, a))
        {
            cout << now << endl;
            return 0;
        }
    }

    return 0;
}