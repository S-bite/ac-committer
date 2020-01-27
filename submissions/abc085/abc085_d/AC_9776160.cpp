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
    int n, h;
    cin >> n >> h;
    vector<int> a(n), b(n);
    vector<pair<int, int>> c(2 * n);

    rep(i, n)
    {
        cin >> a[i] >> b[i];
        c[2 * i] = {a[i], 0};
        c[2 * i + 1] = {b[i], 1};
    }
    sort(ALL(c), greater<pair<int, int>>());
    int ans = 0;
    rep(i, 2 * n)
    {
        if (c[i].second == 0)
        {
            ans += (h + c[i].first - 1) / c[i].first;
            break;
        }
        else
        {
            ans += 1;
            h -= c[i].first;
        }
        if (h <= 0)
        {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
