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
    int n, r;
    cin >> n >> r;
    string s;
    cin >> s;
    int ans = 0;
    int cur = 0;
    int last = n;
    while (cur < n)
    {
        bool ok = true;
        rep(i, n)
        {
            ok &= s[i] == 'o';
            if (s[i] == '.')
                last = i;
        }
        cerr << s << endl;
        cerr << last << endl;
        if (ok)
            break;
        if (s[cur] == '.' || cur + r > last)
        {

            rep(i, cur, min(n, cur + r))
            {
                s[i] = 'o';
            }
        }
        else
        {
            cur++;
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}