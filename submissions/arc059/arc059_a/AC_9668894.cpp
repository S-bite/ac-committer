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
    int ans = (1 << 30);
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    rep(i, -100, 100 + 1)
    {
        int tmp = 0;
        rep(j, n)
        {
            tmp += (a[j] - i) * (a[j] - i);
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
