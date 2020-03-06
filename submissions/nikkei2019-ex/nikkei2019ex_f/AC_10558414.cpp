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
    rep(i, 1, n + 1)
    {
        bool num = true;
        rep(j, 5)
        {
            if (i % (j + 2) == 0)
            {
                num = false;
                cout << (char)('a' + j);
            }
        }
        if (num)
            cout << i;
        cout << endl;
    }
    return 0;
}