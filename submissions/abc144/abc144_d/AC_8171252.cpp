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

int main(int argc, char const *argv[])
{
    lld a, b, x;
    cin >> a >> b >> x;
    if (a * a * b / 2 <= x)
    {
        lld ans = atan((2.0 * b / a) - (2.0 * x / (a * a * a)));
        //cerr << ans << endl;
        printf("%.10Lf\n", ans * (180.0 / M_PI));
    }
    else
    {
        lld ans = M_PI / 2 - atan(2.0 * x / (a * b * b));
        //cerr << ans << endl;
        printf("%.10Lf\n", ans * (180.0 / M_PI));
    }
    return 0;
}
