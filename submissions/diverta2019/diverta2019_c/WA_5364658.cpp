#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
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
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    int a = 0;
    int b = 0;
    int both = 0;
    int base = 0;
    rep(i, n)
    {
        rep(j, 1, s[i].size())
        {
            if (s[i][j - 1] == 'A' && s[i][j] == 'B')
            {
                base++;
            }
        }
        if (s[i][0] == 'B' && s[i][s[i].size() - 1] == 'A')
        {
            both++;
        }
        else if (s[i][0] == 'B')
        {
            b++;
        }
        else if (s[i][s[i].size() - 1] == 'A')
        {
            a++;
        }
    }
    cerr << a << "," << b << "," << both << "," << base << endl;
    ll ans = 0;
    ans += base;
    if (both > 0)
    {
        ans += min(min(a, b), both) * 2;
        if (both > min(a, b))
        {
            both -= min(a, b);
            if (both > 0)
            {
                ans += both - 1;
                if (a != b)
                    ans++;
            }
        }
        else
        {
            ans += min(a, b) - both;
        }
    }
    else
    {
        ans += min(a, b);
    }

    cout << ans << endl;
    return 0;
}
