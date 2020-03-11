#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;
const lld PI = acos(-1);

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0;
    rep(i, n)
    {
        string s;
        int d;
        cin >> s >> d;
        if (d < a)
            d = a;
        if (d > b)
            d = b;
        if (s == "East")
            ans += d;
        else
            ans -= d;
    }
    if (ans == 0)
    {
        cout << ans << endl;
    }
    else if (ans < 0)
    {
        cout << "West"
             << " " << abs(ans) << endl;
    }
    else
    {
        cout << "East"
             << " " << abs(ans) << endl;
    }

    return 0;
}
