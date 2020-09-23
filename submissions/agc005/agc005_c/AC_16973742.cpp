#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

const double EPS = 1e-3;
const double PI = 3.1415926535897932384626433832795028841971;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;
int main()
{
    int n;
    cin >> n;
    map<int, int> mp;
    int mx = -1;
    int mn = IINF;
    rep(i, n)
    {
        int t;
        cin >> t;
        mp[t]++;
        mx = max(mx, t);
        mn = min(mn, t);
    }
    assert(mx >= mn);
    if (mx == 1)
    {
        if (n == 2)
        {
            cout << "Possible" << endl;
        }
        else
        {
            cout << "Impossible" << endl;
        }
        return 0;
    }
    if (mp[mx] == 1)
    {
        cout << "Impossible" << endl;
        return 0;
    }
    if ((mx + 1) / 2 != mn)
    {
        cout << "Impossible" << endl;
        return 0;
    }
    for (int i = mx; i > mn; i--)
    {
        if (mp[i] <= 1)
        {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    if (mx % 2 == 0)
    {
        if (mp[mn] != 1)
        {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    else
    {

        if (mp[mn] != 2)
        {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    cout << "Possible" << endl;
    return 0;
}