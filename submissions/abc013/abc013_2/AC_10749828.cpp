#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int ans1 = 0, ans2 = 0;
    int cur = a;
    while (cur != b)
    {
        cur++;
        ans1++;
        if (cur > 9)
            cur = 0;
    }
    cur = a;
    while (cur != b)
    {
        cur--;
        ans2++;
        if (cur < 0)
            cur = 9;
    }
    cout << min(ans1, ans2) << endl;
    return 0;
}
