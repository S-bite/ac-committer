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
    int n;
    cin >> n;
    int ans = 0;
    if (n < 100)
    {
        ans = 0;
    }
    else if (n < 5000)
    {
        ans = n / 100;
    }
    else if (n < 30000)
    {
        ans = n / 1000 + 50;
    }
    else if (n < 70000)
    {
        ans = ((n / 1000) - 30) / 5 + 80;
    }
    else
    {
        ans = 89;
    }
    printf("%02d\n", ans);
    return 0;
}