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
    vector<int> a(n, 0);
    int q;
    cin >> q;
    rep(i, q)
    {
        int l, r, t;
        cin >> l >> r >> t;
        rep(j, l - 1, r) a[j] = t;
    }
    rep(i, n) cout << a[i] << endl;
    return 0;
}
