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

int main(int argc, char const *argv[])
{
    int a, b, n;
    cin >> a >> b >> n;
    string s;
    cin >> s;
    rep(i, n)
    {
        if (s[i] == 'S')
        {
            a = max(0, a - 1);
        }
        else if (s[i] == 'C')
        {
            b = max(0, b - 1);
        }
        else
        {
            if (b > a)
            {
                b = max(0, b - 1);
            }
            else
            {
                a = max(0, a - 1);
            }
        }
    }
    cout << a << endl
         << b << endl;
    return 0;
}
