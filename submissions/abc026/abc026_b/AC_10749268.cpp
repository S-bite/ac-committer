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

    const lld PI = acos(-1);

    int n;
    cin >> n;
    vector<lld> v(n);
    rep(i, n) cin >> v[i];
    sort(ALL(v), greater<lld>());
    lld ans = 0;
    rep(i, n)
    {
        cerr << v[i] << endl;
        if (i % 2 == 0)
        {
            ans += v[i] * v[i] * PI;
        }
        else
        {
            ans -= v[i] * v[i] * PI;
        }
    }
    cout << fixed << setprecision(18) << ans << endl;
    return 0;
}
