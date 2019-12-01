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
const ll MOD = 1000000007;
using namespace std;

int main(int argc, char const *argv[])
{
    ll t1, t2;
    cin >> t1 >> t2;
    ll a1, a2, b1, b2;
    cin >> a1 >> a2;
    cin >> b1 >> b2;
    ll c1 = (a1 - b1) * t1;
    ll c2 = (a2 - b2) * t2;
    cerr << c1 << " " << c2 << endl;
    if (c1 + c2 == 0)
    {
        cout << "infinity" << endl;
        return 0;
    }

    ll ans = 0;
    if (c1 > 0)
    {
        c1 *= -1;
        c2 *= -1;
    }
    if (c1 + c2 < 0)
    {
        ans = 0;
    }
    else
    {
        cerr << "n" << endl;
        ll s = (-c1) / (c1 + c2);
        ll t = (-c1) % (c1 + c2);
        ans = s * 2 + (t == 0 ? 0 : 1);
    }
    cout << ans << endl;
    return 0;
}
