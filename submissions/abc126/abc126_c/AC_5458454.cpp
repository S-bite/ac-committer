#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
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
    int n, k;
    cin >> n >> k;
    double ans = 0.0;
    rep(i, 1, n + 1)
    {
        int x = i;
        double c = 1.0;

        while (x < k)
        {
            //cerr << x << "," << n << endl;
            x *= 2;
            c /= 2;
        }
        // cerr << c << endl;
        ans += c;
    }
    cout << std::setprecision(18) << ans / (double)n << endl;
    return 0;
}
