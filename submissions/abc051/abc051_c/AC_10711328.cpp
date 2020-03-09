#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
const ll INF = 1ll << 60;

int main()
{
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int dx = tx - sx;
    int dy = ty - sy;
    rep(i, dx) cout << "R";
    rep(i, dy) cout << "U";

    rep(i, dx) cout << "L";
    rep(i, dy) cout << "D";
    cout << "D";
    rep(i, dx + 1) cout << "R";
    rep(i, dy + 1) cout << "U";
    cout << "L";

    cout << "U";
    rep(i, dx + 1) cout << "L";
    rep(i, dy + 1) cout << "D";
    cout << "R";

    cout << endl;

    return 0;
}