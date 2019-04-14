#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <iomanip>
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
    int n;
    cin >> n;
    if (n != 2)
    {
        cout << "This problem is too difficult for me :(" << endl;
        return 0;
    }
    lld x1, x2, r1, r2;
    cin >> x1 >> r1 >> x2 >> r2;
    lld r3;
    if (labs(r1 - r2) >= min(r1, r2))
        r3 = -1;
    r3 = powl(powl(max(r1, r2), 3) + powl(min(r1, r2) - abs(r1 - r2) + 1, 3), (lld)1.0 / 3.0);
    cout << setprecision(12) << max({r1, r2, r3}) << endl;
    return 0;
}