#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
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
    int r, g, b, n;
    ll ans = 0;
    cin >> r >> g >> b >> n;
    rep(i, n + 1)
    {
        rep(j, n + 1)
        {
            if ((n >= r * i + g * j) && (n - r * i - g * j) % b == 0)
            {
                //     cerr << i << "," << j << "," << n - i - j << endl;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
