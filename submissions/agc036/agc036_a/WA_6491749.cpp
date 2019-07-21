
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
    ll s;
    cin >> s;
    ll ax, ay, bx, by;
    ax = ay = bx = by = 0;
    while (s - ax * by >= 0)
    {
        if (ax > by)
        {
            by++;
        }
        else
        {
            ax++;
        }
    }
    ay = 1;
    bx = -(s - ax * by);
    assert(ax <= 1e18);
    assert(ay <= 1e18);
    assert(bx <= 1e18);
    assert(by <= 1e18);
    //assert(cx <= 1e18);
    //assert(cy <= 1e18);

    cout << "0 0 " << ax << " " << ay << " " << bx << " " << by << endl;
    ;

    return 0;
}
