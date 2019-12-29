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
    int n, k;
    cin >> n >> k;
    int r, s, p;
    cin >> r >> s >> p;
    string t;
    cin >> t;
    ll ans = 0;
    vector<char> log(n, '@');
    rep(i, n)
    {
        if (i < k || (i >= k && log[i - k] != t[i]))
        {
            if (t[i] == 'r')
            {
                ans += p;
            }
            else if (t[i] == 's')
            {
                ans += r;
            }
            else if (t[i] == 'p')
            {
                ans += s;
            }
            log[i] = t[i];
        }
    }
    cout << ans << endl;
    return 0;
}
