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
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (char c : s)
    {
        if (((c - '0') % 3) == 1)
        {
            a++;
        }
        if (((c - '0') % 3) == 2)
        {
            b++;
        }
    }
    a %= 3;
    b %= 3;
    if (a < b)
        swap(a, b);
    a -= b;
    if (s.size() <= (a % 3))
    {
        cout << -1 << endl;
    }
    else
    {
        cout << a % 3 << endl;
    }
    return 0;
}