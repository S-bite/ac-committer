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
    ll m, k;
    cin >> m >> k;
    if (k == 0)
    {
        rep(i, (1ll << m))
        {
            cout << i << " " << i << " ";
        }
        cout << endl;
    }
    else
    {
        if (k >= (1ll << m) || (m == 1))
        {
            cout << -1 << endl;
            return 0;
        }
        else
        {
            rep(i, (1ll << m))
            {
                if (i != k)
                    cout << i << " ";
            }
            cout << k << " ";
            for (ll i = (1ll << m) - 1; i >= 0; i--)
            {
                if (i != k)
                    cout << i << " ";
            }
            cout << k << endl;
        }
    }
    return 0;
}
