#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
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

bool ok(vector<ll> v, ll t, ll a, ll b)
{
    cerr << t << "," << a << "," << b << endl;
    rep(i, v.size())
    {
        v[i] -= b * t;
    }

    sort(ALL(v), greater<ll>());
    ll ind = 0;
    ll diff = a - b;
    while (t > 0 && ind < v.size())
    {
        if (v[ind] <= 0)
        {
            ind++;
            continue;
        }
        ll cost = min(t, (v[ind] + diff - 1) / diff);
        v[ind] -= cost * diff;
        t -= cost;
    }
    sort(ALL(v), greater<ll>());

    return (v[0] <= 0);
}

int main(int argc, char const *argv[])
{
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> h;
    rep(i, n)
    {
        ll t;
        cin >> t;
        h.push_back(t);
    }
    ll r = 2000000001ll;
    ll l = -1;
    while (l + 1 != r)
    {
        cerr << r << "," << l << endl;
        ll med = (r + l) / 2;
        if (ok(h, med, a, b))
        {
            cerr << "ok" << endl;
            r = med;
        }
        else
        {
            cerr << "ng" << endl;

            l = med;
        }
    }
    cout << r << endl;
    return 0;
}
