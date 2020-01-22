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
    lld n, r, m;
    cin >> r >> n >> m;
    lld diff = (lld)2 * r / n;
    cerr << diff << endl;
    lld ans = 0;
    rep(i, 1, n + m)
    {
        lld l1, l2;
        if (i - m < 0)
        {
            l1 = 0.0;
        }
        else
        {
            cerr << "ok" << endl;
            lld y = r - diff * (i - m);
            l1 = 2 * sqrt(r * r - y * y);
        }
        if (i >= n)
        {
            l2 = 0.0;
        }
        else
        {
            lld y = r - diff * i;
            l2 = 2 * sqrt(r * r - y * y);
            cerr << y << endl;
        }
        cerr << fixed << setprecision(15) << l1 << " " << l2 << endl;
        ans += max(l1, l2);
    }

    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}
