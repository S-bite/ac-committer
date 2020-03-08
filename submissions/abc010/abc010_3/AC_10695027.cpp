#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

lld dist(lld a, lld b, lld x, lld y)
{
    return sqrt((a - x) * (a - x) + (b - y) * (b - y));
}

int main(int argc, char const *argv[])
{
    lld sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    lld t, v;
    cin >> t >> v;
    bool flag = false;
    int n;
    cin >> n;
    rep(i, n)
    {
        lld x, y;
        cin >> x >> y;
        flag |= (dist(sx, sy, x, y) + dist(x, y, ex, ey) <= t * v);
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
