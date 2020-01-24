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
    string s;
    cin >> s;
    reverse(ALL(s));
    rep(i, s.size())
    {
        if (i + 1 < s.size() && s[i] == 'h' && s[i + 1] == 'c')
        {
            i++;
            continue;
        }
        if (s[i] == 'o' || s[i] == 'k' || s[i] == 'u')
        {
            continue;
        }
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}
