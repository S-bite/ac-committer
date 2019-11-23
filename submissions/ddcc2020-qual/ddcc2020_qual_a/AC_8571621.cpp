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
    int x, y;
    cin >> x >> y;
    if (x == 1 && y == 1)
    {
        cout << 300000 * 2 + 400000 << endl;
        return 0;
    }
    else
    {
        int sum = 0;
        if (x <= 3)
        {
            sum += 100000 * (4 - x);
        }
        if (y <= 3)
        {
            sum += 100000 * (4 - y);
        }
        cout << sum << endl;
        return 0;
    }
    return 0;
}
