#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
const ll INF = (1ll << 60);
bool isok(ll m, ll k, vector<ll> &a, vector<ll> &f)
{
    ll cost = 0;
    rep(i, a.size())
    {
        if (a[i] * f[i] <= m)
            continue;
        cost += a[i] - (m / f[i]);
    }
    return cost <= k;
}

int main(int argc, char const *argv[])
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), f(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> f[i];
    sort(ALL(a));
    sort(ALL(f), greater<ll>());
    rep(i, n) cerr << a[i] << " ";
    cerr << endl;
    rep(i, n) cerr << f[i] << " ";
    cerr << endl;
    ll l = -1;
    ll r = INF;
    while (l + 1 != r)
    {
        ll mid = (l + r) / 2;
        if (isok(mid, k, a, f))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    cout << r << endl;
    return 0;
}
