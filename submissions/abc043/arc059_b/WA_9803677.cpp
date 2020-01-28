#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
#ifdef DEBUG
#define line() cerr << "[" << __LINE__ << "] ";
#define dump(i) cerr << #i ": " << i << " ";
#define dumpl(i) cerr << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
using namespace std;
const int IINF = (1 << 30);

const ll MOD = 1e9 + 7;

bool isok2(string s)
{
    assert(s.size() == 2);
    return s[0] == s[1];
}

bool isok3(string s)
{
    assert(s.size() == 3);
    return s[0] == s[1] || s[0] == s[2] || s[1] == s[2];
}

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    rep(i, s.size())
    {
        if (i + 2 < s.size())
        {
            if (isok2(s.substr(i, 2)))
            {
                cout << i + 1 << " " << i + 3 << endl;
                return 0;
            }
        }
        if (i + 3 < s.size())
        {
            if (isok3(s.substr(i, 3)))
            {
                cout << i + 1 << " " << i + 4 << endl;
                return 0;
            }
        }
    }
    cout << -1 << " " << -1 << endl;
    return 0;
}
