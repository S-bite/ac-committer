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
    int n;
    cin >> n;
    vector<int> c(n - 1), s(n - 1), f(n - 1);
    rep(i, n - 1) cin >> c[i] >> s[i] >> f[i];
    rep(i, n)
    {
        int ans = 0;
        rep(j, i, n - 1)
        {
            if (ans < s[j])
            {
                ans = s[j];
            }
            else
            {
                ans = ((ans + f[j] - 1) / f[j]) * f[j];
            }
            ans += c[j];
        }
        cout << ans << endl;
    }
    return 0;
}