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

int main()
{
    long long h, w, x, y;
    cin >> w >> h >> x >> y;
    long double ans = (h * w) / 2.0;
    if ((w % 2 == 0) && (h % 2 == 0) && (x == w / 2) && (y == h / 2))
    {
        cout << setprecision(17) << ans << " " << 1 << endl;
    }
    else
    {
        cout << setprecision(17) << ans << " " << 0 << endl;
    }
    return 0;
}