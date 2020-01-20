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

bool isevenstring(string s)
{
    if (s.size() % 2 == 1)
    {
        return false;
    }
    int half = s.size() / 2;
    rep(i, half)
    {
        if (s[i] != s[half + i])
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{

    string s;
    cin >> s;
    rep(i, 1, s.size())
    {
        cerr << s.substr(0, s.size() - i) << endl;
        if (isevenstring(s.substr(0, s.size() - i)))
        {
            cout << s.size() - i << endl;
            return 0;
        }
    }
    return 0;
}
