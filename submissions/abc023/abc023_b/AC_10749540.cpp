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
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = "b";
    int ans = 0;
    while (t.size() <= s.size())
    {
        if (t == s)
        {
            cout << ans << endl;
            return 0;
        }
        if (ans % 3 == 0)
        {
            t = "a" + t + "c";
        }
        if (ans % 3 == 1)
        {
            t = "c" + t + "a";
        }
        if (ans % 3 == 2)
        {
            t = "b" + t + "b";
        }
        ans++;
    }
    cout << -1 << endl;
    return 0;
}
