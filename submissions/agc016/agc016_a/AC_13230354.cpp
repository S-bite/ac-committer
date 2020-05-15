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

int ans = IINF;

void calc(string s, char c, int num)
{
    bool ok = true;
    rep(i, s.size())
    {
        ok &= s[i] == c;
    }
    if (ok)
    {
        ans = min(ans, num);
        return;
    }
    string t = "";
    rep(i, s.size() - 1)
    {
        if (s[i] == c)
        {
            t += s[i];
        }
        else
        {
            t += s[i + 1];
        }
    }
    calc(t, c, num + 1);
}
int main()
{
    string s;
    cin >> s;
    rep(i, s.size())
    {
        calc(s, s[i], 0);
    }
    cout << ans << endl;
    return 0;
}