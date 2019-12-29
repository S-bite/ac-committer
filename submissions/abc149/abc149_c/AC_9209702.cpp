#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

bool isprime(int x)
{
    int y = 2;
    while (y * y <= x)
    {
        if (x % y == 0)
        {
            return false;
        }
        y++;
    }
    return true;
}
int main()
{
    int x;
    cin >> x;
    while (isprime(x) != true)
    {
        x++;
    }
    cout << x << endl;
    return 0;
}
