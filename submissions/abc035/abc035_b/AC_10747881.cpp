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
    int x = 0, y = 0, k = 0;
    string s;
    cin >> s;
    rep(i, s.size())
    {
        if (s[i] == '?')
        {
            k++;
        }
        else if (s[i] == 'U')
        {
            y++;
        }
        else if (s[i] == 'D')
        {
            y--;
        }
        else if (s[i] == 'L')
        {
            x--;
        }
        else if (s[i] == 'R')
        {
            x++;
        }
    }
    x = abs(x);
    y = abs(y);
    int t;
    cin >> t;
    if (t == 1)
    {
        cout << x + y + k << endl;
        return 0;
    }
    else
    {
        rep(i, k)
        {
            if (x < y)
            {
                y--;
            }
            else
            {
                x--;
            }
            x = abs(x);
            y = abs(y);
        }
    }
    cout << x + y << endl;
    return 0;
}