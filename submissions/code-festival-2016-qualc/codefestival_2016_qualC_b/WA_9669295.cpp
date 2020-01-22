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
    int k, t;
    cin >> k >> t;
    vector<int> a(t);
    rep(i, t)
    {
        cin >> a[i];
    }
    sort(ALL(a));
    if (t == 1)
    {
        cout << k - 1 << endl;
        return 0;
    }
    cout << max(0, a[t - 1] - a[t - 2] - 2) << endl;
    return 0;
}
