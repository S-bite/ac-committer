#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

const ll MOD = 1e9 + 7;

int main(int argc, char const *argv[])
{

    int w, a, b;
    cin >> w >> a >> b;
    if (a < b)
    {
        cout << max(0, b - (a + w)) << endl;
    }
    else
    {
        cout << max(0, a - (b + w)) << endl;
    }
    return 0;
}
