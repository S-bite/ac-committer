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
using namespace std;
ll gcd(ll a, ll b)
{
    if (a > b)
    {
        ll t = a;
        a = b;
        b = t;
    }
    if (a == 0)
    {
        return b;
    }
    return gcd(a, b % a);
}

int main()
{
    ll a, b;
    cin >> a >> b;
    ll g = gcd(a, b);
    //  cerr << "gcd " << g << endl;
    vector<ll> prime;
    bool isp[101010];
    rep(i, 101010) isp[i] = true;
    rep(i, 2, 101010)
    {
        if (isp[i])
        {
            for (int j = 2 * i; j < 101010; j += i)
            {
                isp[j] = false;
            }
            prime.push_back(i);
        }
    }
    ll ans = 0;
    for (auto &x : prime)
    {
        //cerr << x << endl;
        if (g % x == 0)
            ans++;
    }
    cout << ans + 1 << endl;
    return 0;
}