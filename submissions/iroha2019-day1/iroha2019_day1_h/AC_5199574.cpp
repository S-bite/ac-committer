#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#ifdef DEBUG
#define line() cout << "[" << __LINE__ << "] ";
#define dump(i) cout << #i ": " << i << " ";
#define dumpl(i) cout << #i ": " << i << endl;
#else
#define line(i)
#define dump(i)
#define dumpl(i)
#endif
using namespace std;

int main(int argc, char const *argv[])
{

    string s;
    cin >> s;
    string t = "";

    int m = 0;
    rep(i, s.size())
    {
        m += s[i] - '0';
    }
    int n = m;
    if (n % 9 != 0)
        t += "0123456789"[n % 9];
    n -= n % 9;
    while (n != 0)
    {
        t += "9";
        n -= 9;
    }
    if (s == t)
    {
        cerr << "same" << endl;
        if (s[0] == '9' || s.size() == 1)
        {
            t[0] = "0123456789"[t[0] - '0' - 1];
            t = "1" + t;
        }
        else
        {
            t[0] = "0123456789"[t[0] - '0' + 1];
            t[1] = '8';
        }
    }
    cout << t << endl;
    return 0;
}
