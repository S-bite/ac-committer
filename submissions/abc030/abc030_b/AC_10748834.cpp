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
    lld hdeg = 0;
    lld mdeg = 0;
    int h, m;
    cin >> h >> m;
    hdeg = 30 * h;
    rep(i, m)
    {
        mdeg += 6;
        hdeg += 0.5;
    }
    while (mdeg > 360)
        mdeg -= 360;
    while (hdeg > 360)
        hdeg -= 360;
    cout << fixed << setprecision(16) << min(abs(mdeg - hdeg), 360 - abs(mdeg - hdeg)) << endl;
    return 0;
}