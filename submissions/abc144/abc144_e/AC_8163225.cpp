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

bool ok(vector<ll> &a, vector<ll> &f, ll k, ll m)
{
    rep(i, a.size())
    {
        ll aa = m / f[i];
        //cerr << aa << endl;
        assert(f[i] * aa <= m && aa >= 0 && f[i] * (aa + 1) > m);
        k -= max(0ll, (a[i] - aa));
    }
    return k >= 0;
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
    ll l = -1, r = 1e12 + 1;
    while (l + 1 != r)
    {
        ll med = (l + r) / 2;
        if (ok(a, f, k, med))
        {
            //cerr << "ok" << endl;
            r = med;
        }
        else
        {
            //cerr << "ng" << endl;
            l = med;
        }
    }
    cout << l + 1 << endl;

    return 0;
}
