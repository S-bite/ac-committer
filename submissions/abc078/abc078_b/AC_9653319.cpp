#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

int main(int argc, char const *argv[])
{

    int x, y, z;
    cin >> x >> y >> z;
    int ans = 0;
    if (x < y)
    {
        cout << 0 << endl;
        return 0;
    }
    while (true)
    {
        if (x < z + y)
        {
            break;
        }
        x -= z + y;
        ans++;
    }
    if (x < z)
    {
        ans--;
    }
    cout << ans << endl;
    return 0;
}
