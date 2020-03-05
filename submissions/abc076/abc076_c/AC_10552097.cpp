#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

bool is_ok(string &s, string &t, int pos)
{
    rep(i, t.size())
    {
        if (s[pos + i] != '?' && s[pos + i] != t[i])
        {
            return false;
        }
    }
    return true;
}

void change(string &s, string &t, int pos)
{
    rep(i, t.size())
    {
        s[i + pos] = t[i];
    }
    rep(i, s.size())
    {
        if (s[i] == '?')
            s[i] = 'a';
    }
}
int main(int argc, char const *argv[])
{
    string s, t;
    cin >> s >> t;
    for (int i = s.size() - t.size(); i >= 0; i--)
    {
        if (is_ok(s, t, i))
        {
            change(s, t, i);
            cout << s << endl;
            return 0;
        }
    }
    cout << "UNRESTORABLE" << endl;
    return 0;
}
